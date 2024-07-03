#pragma once

#include <iostream>
#include <variant>

#include "lib/inferlib/data_structure/ConstexprMap.h"
#include "utils/parser/ParsedCommand.h"

namespace codehub::utils {

template <typename Impl>
struct ICommand {
  static void Execute(const ParsedCommand& command) { Impl::ExecuteImpl(command); }
};

}  // namespace codehub::utils
