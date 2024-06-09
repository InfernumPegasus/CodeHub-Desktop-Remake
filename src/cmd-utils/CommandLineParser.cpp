#include "cmd-utils/CommandLineParser.h"

#include "cmd-utils/Command.h"

namespace codehub::utils {

CommandLineParser::CommandLineParser() {
  m_validator = std::make_shared<CommandKeywordValidator>();

  SetUp();
}

std::expected<ParsedCommand, ParserStatus>
CommandLineParser::Parse(int argc, char** argv) {
  if (argc < 2) {
    return std::unexpected<ParserStatus>(ParserStatus::LACK_OF_ARGUMENTS);
  }

  const auto args = ArgvToStringViews(argc, argv);
  const auto flagsWithArgs = ExtractFlagsWithArgs(args);
  const auto simpleArgs = ExtractSimpleArgs(args);
  const CommandArgsList simpleArgsWithoutKeyword{simpleArgs.cbegin() + 1,
                                                 simpleArgs.cend()};

  ParsedCommand command{args.at(1), flagsWithArgs, simpleArgsWithoutKeyword};

  if (const auto status = m_validator->IsValid(command);
      status != ParserStatus::OK) {
    return std::unexpected<ParserStatus>(status);
  }

  return command;
}

constexpr void CommandLineParser::SetUp() {
  const auto setupValidators = [this]() {
    auto flagsValidator = std::make_shared<CommandFlagsValidator>();

    m_validator->SetNext(flagsValidator);
  };

  setupValidators();
}

constexpr CommandArgsList CommandLineParser::ArgvToStringViews(int argc, char** argv) {
  return {argv, argv + argc};
}

constexpr CommandFlagsList CommandLineParser::ExtractFlagsWithArgs(
    const CommandArgsList& rawArgs) {
  CommandFlagsList flagsList;

  for (const auto& arg : rawArgs) {
    if (arg.starts_with("--")) {
      ParsedCommandFlag f;

      if (auto pos = arg.find('='); pos != std::string_view::npos) {
        const auto flag = arg.substr(0, pos);
        const auto value = arg.substr(pos + 1);
        f.m_shouldHaveValue = true;
        f.m_keyValuePair = {flag, value.empty()
                                      ? std::nullopt
                                      : std::make_optional<std::string_view>(value)};
      } else {
        f.m_shouldHaveValue = false;
        f.m_keyValuePair = {arg, std::nullopt};
      }
      flagsList.push_back(f);
    }
  }

  return flagsList;
}

constexpr CommandArgsList CommandLineParser::ExtractSimpleArgs(
    const CommandArgsList& rawArgs) {
  CommandArgsList simpleArgs;
  for (auto it = rawArgs.cbegin() + 1; it != rawArgs.cend(); ++it) {
    if (!it->starts_with("--")) {
      simpleArgs.push_back(*it);
    }
  }
  return simpleArgs;
}

constexpr ParserStatus CommandKeywordValidator::IsValid(
    const ParsedCommand& command) {
  if (!GLOBAL_COMMAND_REGISTRY.Contains(command.m_keyword) || command.m_keyword.empty() ||
      command.m_keyword.starts_with("--")) {
    return ParserStatus::WRONG_KEYWORD;
  }

  if (m_next) return m_next->IsValid(command);

  return ParserStatus::OK;
}

constexpr ParserStatus CommandFlagsValidator::IsValid(
    const ParsedCommand& command) {
  for (const auto& [flag, shouldHaveValue] : command.m_flags) {
    if (flag.first.empty() || (shouldHaveValue && !flag.second.has_value()) ||
        flag.first == "--") {
      return ParserStatus::WRONG_FLAG;
    }
  }

  if (m_next) return m_next->IsValid(command);

  return ParserStatus::OK;
}

}  // namespace codehub::utils