#include "command/VersionCommand.h"

#include "lib/inferlib/Printer.h"
#include "utils/config/VersionInfo.h"

namespace codehub::utils {

void VersionCommand::ExecuteImpl(const ParsedCommand& command) {
  using namespace codehub::version;
  using inferlib::Printer;

  Printer::Println(std::cout, ABOUT);
  Printer::Println(std::cout, "Version:", VERSION);
  Printer::Println(std::cout, "Author:", AUTHOR, AUTHOR_GITHUB);
}

}  // namespace codehub::utils