#pragma once

#include <iostream>
#include <variant>

#include "ParsedCommand.h"

namespace codehub::utils {

class ICommand {
 public:
  virtual ~ICommand() = default;

  virtual void Execute(const ParsedCommand& command) = 0;
};

class HelpCommand : public ICommand {
 public:
  void Execute(const ParsedCommand& command) override { std::cout << "Help command\n"; }
};

class AddCommand : public ICommand {
 public:
  void Execute(const ParsedCommand& command) override { std::cout << "Add command\n"; }
};

}  // namespace codehub::utils
