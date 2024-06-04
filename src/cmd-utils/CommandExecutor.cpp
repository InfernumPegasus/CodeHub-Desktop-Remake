#include "cmd-utils/CommandExecutor.h"

CommandExecutor::CommandExecutor(codehub::utils::CommandRegistry& registry)
    : m_registry(registry) {}

void CommandExecutor::ExecuteCommand(const codehub::utils::ParsedCommand& command) {
  auto cmd = m_registry.GetCommand(command.m_keyword);
  if (cmd) {
    cmd->Execute(command);
  } else {
    inferlib::Printer::Println(std::cerr, "Unknown command: ", command.m_keyword);
  }
}
