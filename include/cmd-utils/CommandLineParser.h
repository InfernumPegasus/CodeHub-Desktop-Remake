#pragma once

#include <algorithm>
#include <expected>
#include <iostream>
#include <memory>
#include <ranges>
#include <string>
#include <string_view>
#include <unordered_map>
#include <utility>
#include <vector>

#include "ParsedCommand.h"
#include "ValidatorBase.h"
#include "lib/inferlib/Printer.h"

namespace codehub::utils {

struct CommandLineParser {
  enum class CommandLineParserStatus : int8_t {
    OK,
    WRONG_KEYWORD,
    WRONG_FLAG,
  };

  CommandLineParser();

  std::expected<ParsedCommand, CommandLineParserStatus> Parse(int argc, char* argv[]);

 private:
  void SetUp();

  static CommandArgsList ArgvToStringViews(int argc, char* argv[]);

  static CommandFlagsList ExtractFlagsWithArgs(const CommandArgsList& rawArgs);

  static CommandArgsList ExtractSimpleArgs(const CommandArgsList& rawArgs);

 private:
  std::shared_ptr<ValidatorBase<ParsedCommand, CommandLineParserStatus>> m_validator;
};

class CommandKeywordValidator
    : public ValidatorBase<ParsedCommand, CommandLineParser::CommandLineParserStatus> {
 public:
  CommandLineParser::CommandLineParserStatus Validate(
      const ParsedCommand& command) override;
};

class CommandFlagsValidator
    : public ValidatorBase<ParsedCommand, CommandLineParser::CommandLineParserStatus> {
 public:
  CommandLineParser::CommandLineParserStatus Validate(
      const ParsedCommand& command) override;
};

}  // namespace codehub::utils
