#include <iostream>

#include "cmd-utils/CommandExecutor.h"
#include "cmd-utils/CommandLineParser.h"
#include "lib/inferlib/Printer.h"

using namespace codehub::utils;

int main(int argc, char* argv[]) {
  CommandLineParser parser;
  auto command = parser.Parse(argc, argv);
  if (command.has_value()) {
    inferlib::Printer::Println(std::cout, command.value());

    constexpr std::array<std::pair<std::string_view, CommandVariant>,
                         std::variant_size_v<CommandVariant>>
        commands{{
            {"help", HelpCommand()},
            {"add", AddCommand()},
        }};

    constexpr codehub::utils::CommandRegistry commandRegistry{{commands}};

    CommandExecutor executor(commandRegistry);
    executor.ExecuteCommand(command.value());
  }

  return 0;
}