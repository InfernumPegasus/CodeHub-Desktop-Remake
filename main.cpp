#include "command/CommandExecutor.h"
#include "utils/cmd/CommandLineParser.h"
#include "utils/error/Error.h"

using namespace codehub::utils;

int main(int argc, char* argv[]) {
  CommandLineParser parser;
  auto result = parser.Parse(argc, argv);

  if (result.has_value()) {
    CommandExecutor::ExecuteCommand(result.value());
  } else {
    PrintError(result.error());
  }

  return 0;
}