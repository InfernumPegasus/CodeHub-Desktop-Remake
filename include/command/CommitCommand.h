#pragma once

#include "ICommand.h"

namespace codehub::utils {

struct CommitCommand : ICommand<CommitCommand> {
  static void ExecuteImpl(const ParsedCommand& command);
};

}  // namespace codehub::utils