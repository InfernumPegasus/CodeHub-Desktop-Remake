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
  bool Validate(const ParsedCommand& command) override {
    if (command.m_keyword.empty()) {
      inferlib::Printer::Println(std::cerr,
                                 "Validation failed: ParsedCommand keyword cannot be empty");
      return false;
    }

    return !m_next || m_next->Validate(command);
  }
};

class CommandFlagsValidator : public ValidatorBase<ParsedCommand> {
 public:
  bool Validate(const ParsedCommand& command) override {
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
};

struct CommandLineParser {
  CommandLineParser();

  auto Parse(std::optional<ParsedCommand> command);

  std::optional<ParsedCommand> Parse(int argc, char* argv[]);

 private:
  CommandArgsList ArgvToStringViews(int argc, char* argv[]);

  CommandFlagsList ExtractFlagsWithArgs(const CommandArgsList& rawArgs);

  CommandArgsList ExtractSimpleArgs(const CommandArgsList& rawArgs);

  std::shared_ptr<ValidatorBase<ParsedCommand>> m_validator;
};

}  // namespace codehub::utils
