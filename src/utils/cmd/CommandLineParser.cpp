#include "utils/cmd/CommandLineParser.h"

#include "command/ICommand.h"

namespace codehub::utils {

ParsedCommand CommandLineParser::Parse(int argc, char** argv) {
  const auto args = ArgvToStringViews(argc, argv);
  const auto flagsWithArgs = ExtractFlagsWithArgs(args);
  const auto simpleArgs = ExtractSimpleArgs(args);
  const auto keyword = !args.empty() ? args.front() : "";

  return {keyword, flagsWithArgs, simpleArgs};
}

constexpr CommandArgsList CommandLineParser::ArgvToStringViews(int argc, char** argv) {
  return {argv + 1, argv + argc - 1};
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
  for (const auto& rawArg : rawArgs) {
    if (!rawArg.starts_with("--")) {
      simpleArgs.push_back(rawArg);
    }
  }
  return simpleArgs;
}

}  // namespace codehub::utils