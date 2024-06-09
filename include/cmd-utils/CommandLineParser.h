#pragma once

#include <expected>
#include <memory>

#include "IValidator.h"
#include "ParsedCommand.h"
#include "logging/Error.h"

namespace codehub::utils {

struct CommandLineParser {
  CommandLineParser();

  std::expected<ParsedCommand, ParserStatus> Parse(int argc, char* argv[]);

 private:
  constexpr void SetUp();

  static constexpr CommandArgsList ArgvToStringViews(int argc, char* argv[]);

  static constexpr CommandFlagsList ExtractFlagsWithArgs(const CommandArgsList& rawArgs);

  static constexpr CommandArgsList ExtractSimpleArgs(const CommandArgsList& rawArgs);

 private:
  std::shared_ptr<IValidator<ParsedCommand, ParserStatus>> m_validator;
};

class CommandKeywordValidator : public IValidator<ParsedCommand, ParserStatus> {
 public:
  constexpr ParserStatus IsValid(const ParsedCommand& command) override;
};

class CommandFlagsValidator : public IValidator<ParsedCommand, ParserStatus> {
 public:
  constexpr ParserStatus IsValid(const ParsedCommand& command) override;
};

}  // namespace codehub::utils
