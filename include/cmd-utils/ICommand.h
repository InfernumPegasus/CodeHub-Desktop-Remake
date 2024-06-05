#pragma once

#include <iostream>
#include <variant>

#include "ParsedCommand.h"

namespace codehub::utils {

class HelpCommand  {
 public:
  void Execute(const ParsedCommand& command) { std::cout << "Help command\n"; }
};

class AddCommand {
 public:
  void Execute(const ParsedCommand& command) { std::cout << "Add command\n"; }
};

}  // namespace codehub::utils
