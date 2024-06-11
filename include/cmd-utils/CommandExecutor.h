#pragma once

#include <iostream>

#include "command/Command.h"

namespace codehub::utils {

class CommandExecutor {
 public:
  static void ExecuteCommand(const ParsedCommand& command);
};

}  // namespace codehub::utils
