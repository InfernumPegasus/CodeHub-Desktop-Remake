#pragma once

#include "utils/cmd/ParsedCommand.h"

namespace codehub::utils {

class CommandExecutor {
 public:
  static void ExecuteCommand(const ParsedCommand& command);
};

}  // namespace codehub::utils
