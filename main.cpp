#include <iostream>

#include "cmd-parser/CommandLineParser.h"
#include "lib/inferlib/Printer.h"

using namespace codehub::utils;

int main(int argc, char* argv[]) {
  CommandLineParser parser;
  auto command = parser.Parse(argc, argv);
  if (command.has_value()) {
    inferlib::Printer::Println(std::cout, command.value());
  } else {}

  return 0;
}