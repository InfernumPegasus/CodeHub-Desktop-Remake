#pragma once

#include "ICommand.h"

namespace codehub::utils {

struct InitCommand : ICommand<InitCommand> {
  static void ExecuteImpl(const ParsedCommand& command);
};

}  // namespace codehub::utils