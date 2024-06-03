#include "cmd-parser/CommandLineParser.h"

codehub::utils::CommandLineParser::CommandLineParser() {
  m_validator = std::make_shared<CommandKeywordValidator>();

  SetUp();
}

void codehub::utils::CommandLineParser::SetUp() {
  const auto setupValidators = [this]() {
    auto flagsValidator = std::make_shared<CommandFlagsValidator>();

    m_validator->SetNext(flagsValidator);
  };

  setupValidators();
}

std::optional<codehub::utils::ParsedCommand> codehub::utils::CommandLineParser::Parse(
    int argc, char** argv) {
  const auto args = ArgvToStringViews(argc, argv);
  const auto flagsWithArgs = ExtractFlagsWithArgs(args);
  const auto simpleArgs = ExtractSimpleArgs(args);
  const CommandArgsList simpleArgsWithoutKeyword{simpleArgs.cbegin() + 1,
                                                 simpleArgs.cend()};

  ParsedCommand command{simpleArgs.front(), flagsWithArgs, simpleArgsWithoutKeyword};

  if (!m_validator->Validate(command)) {
    return std::nullopt;
  }

  return command;
}

codehub::utils::CommandArgsList codehub::utils::CommandLineParser::ArgvToStringViews(
    int argc, char** argv) {
  return {argv, argv + argc};
}

codehub::utils::CommandFlagsList codehub::utils::CommandLineParser::ExtractFlagsWithArgs(
    const codehub::utils::CommandArgsList& rawArgs) {
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

codehub::utils::CommandArgsList codehub::utils::CommandLineParser::ExtractSimpleArgs(
    const codehub::utils::CommandArgsList& rawArgs) {
  CommandArgsList simpleArgs;
  std::ranges::copy_if(
      rawArgs | std::views::drop(1), std::back_inserter(simpleArgs),
      [](const std::string_view& arg) { return !arg.starts_with("--"); });
  return simpleArgs;
}

bool codehub::utils::CommandKeywordValidator::Validate(
    const codehub::utils::ParsedCommand& command) {
  if (command.m_keyword.empty()) {
    inferlib::Printer::Println(
        std::cerr, "Validation failed: ParsedCommand keyword cannot be empty");
    return false;
  }

  return !m_next || m_next->Validate(command);
}

bool codehub::utils::CommandFlagsValidator::Validate(
    const codehub::utils::ParsedCommand& command) {
  for (const auto& [flag, shouldHaveValue] : command.m_flags) {
    if (flag.first.empty() || (shouldHaveValue && !flag.second.has_value()) ||
        flag.first == "--") {
      inferlib::Printer::Println(
          std::cerr, "Validation failed: ParsedCommand flag or value cannot be empty");
      return false;
    }
  }

  return !m_next || m_next->Validate(command);
}
