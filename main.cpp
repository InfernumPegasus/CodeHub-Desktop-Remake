#include <iostream>

#include "cmd-utils/CommandExecutor.h"
#include "cmd-utils/CommandLineParser.h"
#include "lib/inferlib/Printer.h"

using namespace codehub::utils;

// TODO : move into logging module
void PrintCommandLineParserStatusError(
    CommandLineParser::CommandLineParserStatus status) {
  switch (status) {
    case CommandLineParser::CommandLineParserStatus::UNKNOWN_COMMAND_KEYWORD:
      inferlib::Printer::Println(std::cerr, "Error: No such command");
      break;
    case CommandLineParser::CommandLineParserStatus::WRONG_KEYWORD:
      inferlib::Printer::Println(std::cerr, "Error: Wrong command keyword format");
      break;
    case CommandLineParser::CommandLineParserStatus::WRONG_FLAG:
      inferlib::Printer::Println(std::cerr, "Error: Wrong command flag or value format");
      break;
    default:
      inferlib::Printer::Println(std::cerr, "Error: Unknown error occurred");
      break;
  }
}

int main(int argc, char* argv[]) {
  CommandLineParser parser;
  auto result = parser.Parse(argc, argv);

  if (result.has_value()) {
    auto command = result.value();
    inferlib::Printer::Println(std::cout, command);

    CommandExecutor::ExecuteCommand(command);
  } else {
    auto errorStatus = result.error();
    PrintCommandLineParserStatusError(errorStatus);
  }

  return 0;
}