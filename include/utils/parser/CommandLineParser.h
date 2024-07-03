#pragma once

#include <expected>
#include <memory>

#include "ParsedCommand.h"
#include "utils/error/Error.h"

namespace codehub::utils {

struct CommandLineParser {
  [[nodiscard]] static ParsedCommand Parse(int argc, char* argv[]);

 private:
  [[nodiscard]] static constexpr CommandArgsList ArgvToStringViews(int argc,
                                                                   char* argv[]);

  [[nodiscard]] static constexpr CommandFlagsList ExtractFlagsWithArgs(
      const CommandArgsList& rawArgs);

  [[nodiscard]] static constexpr CommandArgsList ExtractSimpleArgs(
      const CommandArgsList& rawArgs);
};

}  // namespace codehub::utils
