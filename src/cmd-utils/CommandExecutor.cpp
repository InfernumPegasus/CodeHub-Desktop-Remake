#include "cmd-utils/CommandExecutor.h"

codehub::utils::CommandExecutor::CommandExecutor(
    const codehub::utils::CommandRegistry& registry)
    : m_commandRegistry(registry) {}

void codehub::utils::CommandExecutor::ExecuteCommand(
    const codehub::utils::ParsedCommand& parsedCommand) {
  try {
    auto cmd = m_commandRegistry.at(parsedCommand.m_keyword);
    std::visit([&parsedCommand](auto& cmd) { cmd.Execute(parsedCommand); }, cmd);
  } catch (const std::range_error&) {
    inferlib::Printer::Println(std::cerr, "Unknown command: ", parsedCommand.m_keyword);
  }
}