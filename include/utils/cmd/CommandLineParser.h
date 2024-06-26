#pragma once

#include <expected>
#include <memory>

#include "IValidator.h"
#include "ParsedCommand.h"
#include "utils/error/Error.h"

namespace codehub::utils {

struct CommandLineParser {
  static ParsedCommand Parse(int argc, char* argv[]);

 private:
  static constexpr CommandArgsList ArgvToStringViews(int argc, char* argv[]);

  static constexpr CommandFlagsList ExtractFlagsWithArgs(const CommandArgsList& rawArgs);

  static constexpr CommandArgsList ExtractSimpleArgs(const CommandArgsList& rawArgs);
};

}  // namespace codehub::utils
