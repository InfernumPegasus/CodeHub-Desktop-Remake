#pragma once

#include "ParserUtils.h"
#include "utils/error/Error.h"

namespace codehub::utils {

struct CommandLineParser {
  [[nodiscard]] static ParsedCommand Parse(int argc, char* argv[]);

 private:
  [[nodiscard]] static constexpr ArgsListView ArgvToStringViews(int argc, char* argv[]);

  [[nodiscard]] static constexpr FlagsListView ExtractFlagsWithArgs(
      const ArgsListView& rawArgs);

  [[nodiscard]] static constexpr ArgsListView ExtractSimpleArgs(
      const ArgsListView& rawArgs);
};

}  // namespace codehub::utils
