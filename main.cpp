#include <iostream>

#include "cmd-utils/CommandExecutor.h"
#include "cmd-utils/CommandLineParser.h"
#include "lib/inferlib/Printer.h"
#include "logging/Error.h"

using namespace codehub::utils;

int main(int argc, char* argv[]) {
  CommandLineParser parser;
  auto result = parser.Parse(argc, argv);

  if (result.has_value()) {
    auto command = result.value();
    inferlib::Printer::Println(std::cout, command);

    CommandExecutor::ExecuteCommand(command);
  } else {
    auto errorStatus = result.error();
    PrintError(errorStatus);
  }

  return 0;
}