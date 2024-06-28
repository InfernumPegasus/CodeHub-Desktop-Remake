#pragma once

#include "ICommand.h"

namespace codehub::utils {

struct AddCommand : ICommand<AddCommand> {
  static void ExecuteImpl(const ParsedCommand& command);
};

}  // namespace codehub::utils