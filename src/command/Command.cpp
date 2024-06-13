#include "command/Command.h"

#include <iomanip>
#include <iostream>

#include "lib/inferlib/Printer.h"
#include "utils/cmd/ParsedCommand.h"

namespace codehub::utils {

void utils::HelpCommand::ExecuteImpl(const ParsedCommand& command) {
  using namespace inferlib;

  constexpr size_t maxNameLength =
      std::max_element(
          COMMAND_DESCRIPTIONS.data.begin(), COMMAND_DESCRIPTIONS.data.end(),
          [](const auto& a, const auto& b) { return a.first.size() < b.first.size(); })
          ->first.size();

  Printer::Println(std::cout, "Available commands:");
  for (const auto& [name, description] : COMMAND_DESCRIPTIONS.data) {
    Printer::Println(std::cout, name,
                     std::setw(static_cast<int>(maxNameLength - name.size() + 2)), " - ",
                     description);
  }
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