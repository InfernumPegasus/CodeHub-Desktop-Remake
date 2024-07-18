#include "command/VersionCommand.h"

#include "lib/inferlib/printer/Printer.h"
#include "utils/config/VersionInfo.h"

namespace codehub::utils {

CommandExecutionStatus VersionCommand::ExecuteImpl(const ParsedCommand& ) {
  using namespace codehub::version;
  using inferlib::Printer;

  Printer::Println(std::cout, ABOUT);
  Printer::Println(std::cout, "Version:", VERSION);
  Printer::Println(std::cout, "Author:", AUTHOR, "| Link:", AUTHOR_GITHUB);

  return CommandExecutionStatus::OK;
}

}  // namespace codehub::utils