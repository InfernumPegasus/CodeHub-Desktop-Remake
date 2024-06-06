#include "cmd-utils/CommandLineParser.h"

#include "cmd-utils/Command.h"

namespace codehub::utils {

CommandLineParser::CommandLineParser() {
  m_validator = std::make_shared<CommandKeywordValidator>();

  SetUp();
}

std::expected<ParsedCommand, CommandLineParser::CommandLineParserStatus>
CommandLineParser::Parse(int argc, char** argv) {
  const auto args = ArgvToStringViews(argc, argv);
  const auto flagsWithArgs = ExtractFlagsWithArgs(args);
  const auto simpleArgs = ExtractSimpleArgs(args);
  const CommandArgsList simpleArgsWithoutKeyword{simpleArgs.cbegin() + 1,
                                                 simpleArgs.cend()};

  ParsedCommand command{args.at(1), flagsWithArgs, simpleArgsWithoutKeyword};

  if (const auto status = m_validator->Validate(command);
      status != CommandLineParserStatus::OK) {
    return std::unexpected<CommandLineParserStatus>(status);
  }

  return command;
}

void CommandLineParser::SetUp() {
  const auto setupValidators = [this]() {
    auto flagsValidator = std::make_shared<CommandFlagsValidator>();

    m_validator->SetNext(flagsValidator);
  };

  setupValidators();
}

CommandArgsList CommandLineParser::ArgvToStringViews(int argc, char** argv) {
  return {argv, argv + argc};
}

CommandFlagsList CommandLineParser::ExtractFlagsWithArgs(const CommandArgsList& rawArgs) {
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

CommandArgsList CommandLineParser::ExtractSimpleArgs(const CommandArgsList& rawArgs) {
  CommandArgsList simpleArgs;
  for (auto it = rawArgs.cbegin() + 1; it != rawArgs.cend(); ++it) {
    if (!it->starts_with("--")) {
      simpleArgs.push_back(*it);
    }
  }
  return simpleArgs;
}

CommandLineParser::CommandLineParserStatus CommandKeywordValidator::Validate(
    const ParsedCommand& command) {
  if (!GLOBAL_COMMAND_REGISTRY.Contains(command.m_keyword)) {
    return CommandLineParser::CommandLineParserStatus::UNKNOWN_COMMAND_KEYWORD;
  }
  if (command.m_keyword.empty() || command.m_keyword.starts_with("--")) {
    return CommandLineParser::CommandLineParserStatus::WRONG_KEYWORD;
  }

  if (m_next) return m_next->Validate(command);

  return CommandLineParser::CommandLineParserStatus::OK;
}

CommandLineParser::CommandLineParserStatus CommandFlagsValidator::Validate(
    const ParsedCommand& command) {
  for (const auto& [flag, shouldHaveValue] : command.m_flags) {
    if (flag.first.empty() || (shouldHaveValue && !flag.second.has_value()) ||
        flag.first == "--") {
      return CommandLineParser::CommandLineParserStatus::WRONG_FLAG;
    }
  }

  if (m_next) return m_next->Validate(command);

  return CommandLineParser::CommandLineParserStatus::OK;
}

}  // namespace codehub::utils