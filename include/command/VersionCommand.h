#pragma once

#include "ICommand.h"

namespace codehub::utils {

struct VersionCommand : ICommand<VersionCommand> {
  static CommandExecutionStatus ExecuteImpl(const ParsedCommand& command);
};

}  // namespace codehub::utils