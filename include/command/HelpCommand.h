#pragma once

#include "ICommand.h"

namespace codehub::utils {

struct HelpCommand : ICommand<HelpCommand> {
  static void ExecuteImpl(const ParsedCommand& command);
};

}  // namespace codehub::utils
