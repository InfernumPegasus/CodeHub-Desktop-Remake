#include "cmd-utils/CommandExecutor.h"

namespace codehub::utils {

CommandExecutor::CommandExecutor(const CommandRegistry& registry)
    : m_commandRegistry(registry) {}

void CommandExecutor::ExecuteCommand(const ParsedCommand& parsedCommand) {
  try {
    auto cmd = m_commandRegistry.At(parsedCommand.m_keyword);
    std::visit([&parsedCommand](auto& cmd) { cmd.Execute(parsedCommand); }, cmd);
  } catch (const std::range_error&) {
    inferlib::Printer::Println(std::cerr, "Unknown command: ", parsedCommand.m_keyword);
  }
}

}