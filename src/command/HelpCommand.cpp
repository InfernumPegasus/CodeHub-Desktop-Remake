#include "command/HelpCommand.h"

#include <iomanip>

#include "command/CommandsUtils.h"
#include "lib/inferlib/printer/Printer.h"

namespace codehub::utils {

CommandExecutionStatus HelpCommand::ExecuteImpl(const ParsedCommand&) {
  using namespace inferlib;
  using namespace command;

  constexpr size_t maxNameLength =
      std::max_element(
          COMMAND_DESCRIPTIONS.data.cbegin(), COMMAND_DESCRIPTIONS.data.cend(),
          [](const auto& a, const auto& b) { return a.first.size() < b.first.size(); })
          ->first.size();

  Printer::Println(std::cout, "Available commands:");
  for (const auto& [name, description] : COMMAND_DESCRIPTIONS.data) {
    Printer::Println(std::cout, name,
                     std::setw(static_cast<int>(maxNameLength - name.size() + 3)), " - ",
                     description);
  }

  return CommandExecutionStatus::OK;
}

}  // namespace codehub::utils