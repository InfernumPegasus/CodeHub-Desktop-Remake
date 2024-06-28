#pragma once

#include <array>
#include <string>
#include <utility>

#include "command/utils/CommandsUtils.h"
#include "utils/parser/ParsedCommand.h"
#include "utils/error/Error.h"

namespace codehub::utils {

template <typename, typename Status>
struct ValidatorResult {
  Status status;
  std::string errorMessage;
};

template <typename Object, typename Status>
using ValidatorFunction = ValidatorResult<Object, Status> (*)(const Object&);

template <typename Object, typename Status, std::size_t N>
class ValidatorChain {
 public:
  constexpr explicit ValidatorChain(
      std::array<ValidatorFunction<Object, Status>, N> validators)
      : validators_(std::move(validators)) {}

  [[nodiscard]] constexpr Status Validate(const Object& obj) const {
    for (auto validator : validators_) {
      auto result = validator(obj);
      if (result.status != Status::OK) {
        return result.status;
      }
    }
    return Status::OK;
  }

 private:
  std::array<ValidatorFunction<Object, Status>, N> validators_;
};

constexpr ValidatorResult<ParsedCommand, ParserStatus> ValidateCommandKeyword(
    const ParsedCommand& command) {
  if (!command.m_keyword.empty() && !command.m_keyword.starts_with("--") &&
      GLOBAL_COMMAND_REGISTRY.Contains(command.m_keyword)) {
    return {ParserStatus::OK, ""};
  }
  return {ParserStatus::WRONG_KEYWORD, "Invalid keyword"};
}

constexpr ValidatorResult<ParsedCommand, ParserStatus> ValidateCommandFlags(
    const ParsedCommand& command) {
  for (const auto& [flag, shouldHaveValue] : command.m_flags) {
    if (flag.first.empty() || (shouldHaveValue && !flag.second.has_value()) ||
        flag.first == "--") {
      return {ParserStatus::WRONG_FLAG, "Invalid flag"};
    }
  }
  return {ParserStatus::OK, ""};
}

template <typename... Validators>
constexpr auto ConstructParserValidator(Validators... validators) {
  return ValidatorChain<ParsedCommand, ParserStatus, sizeof...(validators)>{
      {validators...}};
}

}  // namespace codehub::utils