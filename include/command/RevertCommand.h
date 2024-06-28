#pragma once

#include "ICommand.h"

namespace codehub::utils {

struct RevertCommand : ICommand<RevertCommand> {
  static void ExecuteImpl(const ParsedCommand& command);
};

}  // namespace codehub::utils