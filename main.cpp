#include "command/utils/CommandExecutor.h"
#include "utils/error/Error.h"
#include "utils/parser/CommandLineParser.h"
#include "utils/parser/IniConfigParser.h"
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

  std::vector<std::string> lines = {
      "; некоторый комментарий",
      "# комментарий в стиле Unix",
      "",
      "[Section1]",
      "; комментарий о разделе",
      "var1=val_1 ; иногда допускается комментарий к отдельному параметру",
      "var2=val_2",
      "",
      "[Section2]",
      "var1=val_1",
      "var2=val_2",
      "",
      "; иногда позволяется перечислять несколько значений через запятую",
      "[Section3]",
      "var1=val_1_1, val_1_2, val_1_3 ; AMOGUS",
      "var2=val_2",
      "",
      "; Иногда значения отсутствуют",
      "[ViewState]",
      "Mode=",
      "Vid=",
      "FolderType=Generic",
      "[Section4.0]",
  };

  const auto& parsedIni = IniConfigParser::Parse(lines);

  inferlib::Printer::Println(std::cout, parsedIni);

  return 0;
}