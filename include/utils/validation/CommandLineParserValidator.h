#pragma once

#include "ValidatorChain.h"
#include "command/utils/CommandsUtils.h"
#include "utils/parser/ParsedCommand.h"

namespace codehub::utils {

constexpr auto ValidateCommandKeyword =
    [](const ParsedCommand& command) -> ValidatorResult<ParsedCommand, ParserStatus> {
  if (!command.m_keyword.empty() && !command.m_keyword.starts_with("--") &&
      command::GLOBAL_COMMAND_REGISTRY.Contains(command.m_keyword)) {
    return {ParserStatus::OK, ""};
  }
  return {ParserStatus::WRONG_KEYWORD, "Invalid keyword"};
};

constexpr auto ValidateCommandFlags =
    [](const ParsedCommand& command) -> ValidatorResult<ParsedCommand, ParserStatus> {
  for (const auto& [flag, shouldHaveValue] : command.m_flags) {
    if (flag.first.empty() || (shouldHaveValue && !flag.second.has_value()) ||
        flag.first == "--") {
      return {ParserStatus::WRONG_FLAG, "Invalid flag"};
    }
  }
  return {ParserStatus::OK, ""};
};

}  // namespace codehub::utils
