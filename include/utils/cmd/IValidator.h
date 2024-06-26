#pragma once

#include <memory>

#include "command/ICommand.h"
#include "utils/cmd/ParsedCommand.h"
#include "utils/error/Error.h"

namespace codehub::utils {

template <class Object, class Status>
class IValidator {
 public:
  virtual ~IValidator() = default;

  constexpr void SetNext(std::unique_ptr<IValidator> next) { m_next = std::move(next); }

  constexpr virtual Status IsValid(const Object&) = 0;

 protected:
  std::unique_ptr<IValidator> m_next;
};

class CommandKeywordValidator : public IValidator<ParsedCommand, ParserStatus> {
 public:
  constexpr ParserStatus IsValid(const ParsedCommand& command) override {
    if (!GLOBAL_COMMAND_REGISTRY.Contains(command.m_keyword) ||
        command.m_keyword.empty() || command.m_keyword.starts_with("--")) {
      return ParserStatus::WRONG_KEYWORD;
    }

    if (m_next) return m_next->IsValid(command);

    return ParserStatus::OK;
  }
};

class CommandFlagsValidator : public IValidator<ParsedCommand, ParserStatus> {
 public:
  constexpr ParserStatus IsValid(const ParsedCommand& command) override {
    for (const auto& [flag, shouldHaveValue] : command.m_flags) {
      if (flag.first.empty() || (shouldHaveValue && !flag.second.has_value()) ||
          flag.first == "--") {
        return ParserStatus::WRONG_FLAG;
      }
    }

    if (m_next) return m_next->IsValid(command);

    return ParserStatus::OK;
  }
};

constexpr std::unique_ptr<CommandKeywordValidator> ConstructCommandLineParserValidator() {
  auto commandKeywordValidator = std::make_unique<CommandKeywordValidator>();
  auto flagsValidator = std::make_unique<CommandFlagsValidator>();
  commandKeywordValidator->SetNext(std::move(flagsValidator));

  return commandKeywordValidator;
}

}  // namespace codehub::utils
