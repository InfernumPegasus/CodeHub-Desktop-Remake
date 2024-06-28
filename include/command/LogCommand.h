#pragma once

#include "ICommand.h"

namespace codehub::utils {

struct LogCommand : ICommand<LogCommand> {
  static void ExecuteImpl(const ParsedCommand& command);
};

}  // namespace codehub::utils