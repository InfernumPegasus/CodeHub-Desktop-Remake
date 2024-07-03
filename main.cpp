#include "command/utils/CommandExecutor.h"
#include "utils/error/Error.h"
#include "utils/parser/CommandLineParser.h"
#include "utils/validation/ParserValidator.h"

using namespace codehub::utils;

int main(int argc, char* argv[]) {
  const auto& command = CommandLineParser::Parse(argc, argv);
  constexpr auto validator = ConstructValidatorChain<ParsedCommand, ParserStatus>(
      ValidateCommandKeyword, ValidateCommandFlags);

  if (auto status = validator.Validate(command); status == ParserStatus::OK) {
    inferlib::Printer::Println(std::cout, command);
    CommandExecutor::ExecuteCommand(command);
  } else {
    PrintError(status);
  }

  return 0;
}