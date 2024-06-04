#pragma once

#include <iostream>

#include "CommandRegistry.h"
#include "lib/inferlib/Printer.h"

class CommandExecutor {
 public:
  explicit CommandExecutor(codehub::utils::CommandRegistry& registry);

  void ExecuteCommand(const codehub::utils::ParsedCommand& command);

 private:
  codehub::utils::CommandRegistry& m_registry;
};
