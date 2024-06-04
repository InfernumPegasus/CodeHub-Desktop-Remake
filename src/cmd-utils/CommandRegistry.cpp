#include "cmd-utils/CommandRegistry.h"

void codehub::utils::CommandRegistry::RegisterCommand(
    std::string_view name, CommandRegistry::ICommandPtr&& command) {
  m_commands[name] = std::forward<CommandRegistry::ICommandPtr>(command);
}

codehub::utils::CommandRegistry::ICommandPtr codehub::utils::CommandRegistry::GetCommand(
    std::string_view name) const {
  auto it = m_commands.find(name);
  if (it != m_commands.end()) {
    return it->second;
  }
  return nullptr;
}