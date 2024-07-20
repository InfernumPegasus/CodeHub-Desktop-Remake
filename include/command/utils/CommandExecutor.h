#pragma once

#include "utils/parser/ParsedCommand.h"
#include "utils/parser/ParserUtils.h"
#include "utils/status/Status.h"

namespace codehub::utils {

class CommandExecutor {
 public:
  [[nodiscard]] static CommandExecutionStatus Execute(const ParsedCommand& command);
};

}  // namespace codehub::utils
