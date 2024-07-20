#pragma once

#include <iostream>
#include <variant>

#include "lib/inferlib/data_structure/ConstexprMap.h"
#include "utils/parser/ParsedCommand.h"
#include "utils/status/Status.h"

namespace codehub::utils {

template <typename Impl>
struct ICommand {
  static CommandExecutionStatus Execute(const ParsedCommand& command) {
    return Impl::ExecuteImpl(command);
  }
};

}  // namespace codehub::utils
