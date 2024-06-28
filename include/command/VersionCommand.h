#pragma once

#include "ICommand.h"

namespace codehub::utils {

struct VersionCommand : ICommand<VersionCommand> {
  static void ExecuteImpl(const ParsedCommand& command);
};

}  // namespace codehub::utils