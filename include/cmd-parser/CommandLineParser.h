#pragma once

#include <algorithm>
#include <iostream>
#include <memory>
#include <optional>
#include <ranges>
#include <string>
#include <string_view>
#include <unordered_map>
#include <utility>
#include <vector>

#include "ParsedCommand.h"
#include "lib/inferlib/Printer.h"
#include "lib/inferlib/ValidatorBase.h"

namespace codehub::utils {

class CommandKeywordValidator : public ValidatorBase<ParsedCommand> {
 public:
  bool Validate(const ParsedCommand& command) override;
};

class CommandFlagsValidator : public ValidatorBase<ParsedCommand> {
 public:
  bool Validate(const ParsedCommand& command) override;
};

struct CommandLineParser {
  CommandLineParser();

  std::optional<ParsedCommand> Parse(int argc, char* argv[]);

 private:
  void SetUp();

  static CommandArgsList ArgvToStringViews(int argc, char* argv[]);

  static CommandFlagsList ExtractFlagsWithArgs(const CommandArgsList& rawArgs);

  static CommandArgsList ExtractSimpleArgs(const CommandArgsList& rawArgs);

 private:
  std::shared_ptr<ValidatorBase<ParsedCommand>> m_validator;
};

}  // namespace codehub::utils
