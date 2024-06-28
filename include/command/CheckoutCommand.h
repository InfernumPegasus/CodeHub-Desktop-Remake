#pragma once

#include "ICommand.h"

namespace codehub::utils {

struct CheckoutCommand : ICommand<CheckoutCommand> {
  static void ExecuteImpl(const ParsedCommand& command);
};

}  // namespace codehub::utils