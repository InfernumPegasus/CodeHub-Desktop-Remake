#include "command/ConfigCommand.h"

#include "lib/inferlib/printer/Printer.h"
#include "utils/status/Status.h"

namespace codehub::utils {

CommandExecutionStatus ConfigCommand::ExecuteImpl(const ParsedCommand& command) {
  inferlib::Printer::Println(std::cout, "ConfigCommand is executing!");

  return CommandExecutionStatus::OK;
}

}  // namespace codehub::utils
