#pragma once

#include "ICommand.h"

namespace codehub::utils {

struct RevertCommand : ICommand<RevertCommand> {
  static CommandExecutionStatus ExecuteImpl(const ParsedCommand& command);
};

}  // namespace codehub::utils