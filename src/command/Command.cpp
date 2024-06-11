#include "command/Command.h"

#include "utils/cmd/ParsedCommand.h"

namespace codehub::utils {

void utils::HelpCommand::ExecuteImpl(const ParsedCommand& command) {
  std::cout << "Help command\n";
}

void AddCommand::ExecuteImpl(const ParsedCommand& command) {
  std::cout << "Add command\n";
}

void VersionCommand::ExecuteImpl(const ParsedCommand& command) {
  std::cout << "Version command\n";
}

void LogCommand::ExecuteImpl(const ParsedCommand& command) {
  std::cout << "Log command\n";
}

}  // namespace codehub::utils