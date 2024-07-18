#pragma once

#include "ICommand.h"

namespace codehub::utils {

struct CommitCommand : ICommand<CommitCommand> {
  static CommandExecutionStatus ExecuteImpl(const ParsedCommand& command);
};

}  // namespace codehub::utils