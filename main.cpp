#include <iostream>

#include "cmd-utils/CommandExecutor.h"
#include "cmd-utils/CommandLineParser.h"
#include "cmd-utils/CommandRegistry.h"
#include "lib/inferlib/Printer.h"

using namespace codehub::utils;

int main(int argc, char* argv[]) {
  CommandLineParser parser;
  auto command = parser.Parse(argc, argv);
  if (command.has_value()) {
    inferlib::Printer::Println(std::cout, command.value());

    CommandRegistry registry;
    registry.RegisterCommand("help", std::make_shared<HelpCommand>());
    registry.RegisterCommand("add", std::make_shared<AddCommand>());

    CommandExecutor executor(registry);
    executor.ExecuteCommand(command.value());
  }

  return 0;
}