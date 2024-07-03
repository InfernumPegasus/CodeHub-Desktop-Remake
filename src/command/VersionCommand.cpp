#include "command/VersionCommand.h"

#include "lib/inferlib/printer/Printer.h"
#include "utils/config/VersionInfo.h"

namespace codehub::utils {

void VersionCommand::ExecuteImpl(const ParsedCommand& ) {
  using namespace codehub::version;
  using inferlib::Printer;

  Printer::Println(std::cout, ABOUT);
  Printer::Println(std::cout, "Version:", VERSION);
  Printer::Println(std::cout, "Author:", AUTHOR, "| Link:", AUTHOR_GITHUB);
}

}  // namespace codehub::utils