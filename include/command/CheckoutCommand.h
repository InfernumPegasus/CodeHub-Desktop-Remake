#pragma once

#include "ICommand.h"

namespace codehub::utils {

struct CheckoutCommand : ICommand<CheckoutCommand> {
  static CommandExecutionStatus ExecuteImpl(const ParsedCommand& command);
};

}  // namespace codehub::utils