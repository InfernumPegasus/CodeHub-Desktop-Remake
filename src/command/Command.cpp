#include "command/Command.h"

#include <iomanip>
#include <iostream>

#include "lib/inferlib/Printer.h"
#include "utils/cmd/ParsedCommand.h"
#include "utils/config/VersionInfo.h"

namespace codehub::utils {

void HelpCommand::ExecuteImpl(const ParsedCommand& command) {
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

void ConfigCommand::ExecuteImpl(const ParsedCommand& command) {}

void InitCommand::ExecuteImpl(const ParsedCommand& command) {}

void AddCommand::ExecuteImpl(const ParsedCommand& command) {}

void CommitCommand::ExecuteImpl(const ParsedCommand& command) {}

void RevertCommand::ExecuteImpl(const ParsedCommand& command) {}

void LogCommand::ExecuteImpl(const ParsedCommand& command) {}

void VersionCommand::ExecuteImpl(const ParsedCommand& command) {
  using namespace codehub::version;

  inferlib::Printer::Println(std::cout, ABOUT);
  inferlib::Printer::Println(std::cout, "Version:", VERSION);
  inferlib::Printer::Println(std::cout, "Author:", AUTHOR, AUTHOR_GITHUB);
}

void BranchCommand::ExecuteImpl(const ParsedCommand& command) {}

void CheckoutCommand::ExecuteImpl(const ParsedCommand& command) {}

}  // namespace codehub::utils