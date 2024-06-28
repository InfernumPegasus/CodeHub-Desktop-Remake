#include "command/HelpCommand.h"

#include <iomanip>

#include "command/utils/CommandsUtils.h"
#include "lib/inferlib/Printer.h"

namespace codehub::utils {

void HelpCommand::ExecuteImpl(const ParsedCommand&) {
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

}  // namespace codehub::utils