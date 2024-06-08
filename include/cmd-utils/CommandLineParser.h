#pragma once

#include <expected>
#include <memory>

#include "IValidator.h"
#include "ParsedCommand.h"

namespace codehub::utils {

struct CommandLineParser {
  enum class CommandLineParserStatus : int8_t {
    OK,
    WRONG_KEYWORD,
    WRONG_FLAG,
    LACK_OF_ARGUMENTS,
  };

  CommandLineParser();

  std::expected<ParsedCommand, CommandLineParserStatus> Parse(int argc, char* argv[]);

 private:
  constexpr void SetUp();

  static constexpr CommandArgsList ArgvToStringViews(int argc, char* argv[]);

  static constexpr CommandFlagsList ExtractFlagsWithArgs(const CommandArgsList& rawArgs);

  static constexpr CommandArgsList ExtractSimpleArgs(const CommandArgsList& rawArgs);

 private:
  std::shared_ptr<IValidator<ParsedCommand, CommandLineParserStatus>> m_validator;
};

class CommandKeywordValidator
    : public IValidator<ParsedCommand, CommandLineParser::CommandLineParserStatus> {
 public:
  constexpr CommandLineParser::CommandLineParserStatus IsValid(
      const ParsedCommand& command) override;
};

class CommandFlagsValidator
    : public IValidator<ParsedCommand, CommandLineParser::CommandLineParserStatus> {
 public:
  constexpr CommandLineParser::CommandLineParserStatus IsValid(
      const ParsedCommand& command) override;
};

}  // namespace codehub::utils
