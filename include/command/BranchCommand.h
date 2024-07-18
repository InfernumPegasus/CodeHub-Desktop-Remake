#pragma once

#include "ICommand.h"

namespace codehub::utils {

struct BranchCommand : ICommand<BranchCommand> {
  static CommandExecutionStatus ExecuteImpl(const ParsedCommand& command);
};

}  // namespace codehub::utils