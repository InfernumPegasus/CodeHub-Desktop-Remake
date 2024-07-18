#pragma once

#include "ICommand.h"

namespace codehub::utils {

struct LogCommand : ICommand<LogCommand> {
  static CommandExecutionStatus ExecuteImpl(const ParsedCommand& command);
};

}  // namespace codehub::utils