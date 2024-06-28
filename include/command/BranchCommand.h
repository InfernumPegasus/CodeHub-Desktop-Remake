#pragma once

#include "ICommand.h"

namespace codehub::utils {

struct BranchCommand : ICommand<BranchCommand> {
  static void ExecuteImpl(const ParsedCommand& command);
};

}  // namespace codehub::utils