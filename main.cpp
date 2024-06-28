#include "command/utils/CommandExecutor.h"
#include "utils/cmd/CommandLineParser.h"
#include "utils/error/Error.h"

using namespace codehub::utils;

int main(int argc, char* argv[]) {
  const auto command = CommandLineParser::Parse(argc, argv);
  auto validator = ConstructValidator(ValidateCommandKeyword, ValidateCommandFlags);

  if (auto status = validator.Validate(command); status == ParserStatus::OK) {
    CommandExecutor::ExecuteCommand(command);
  } else {
    PrintError(status);
  }

  return 0;
}