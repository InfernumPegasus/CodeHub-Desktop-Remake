#pragma once

#include "ICommand.h"

namespace codehub::utils {

struct InitCommand : ICommand<InitCommand> {
  static CommandExecutionStatus ExecuteImpl(const ParsedCommand& command);
};

}  // namespace codehub::utils