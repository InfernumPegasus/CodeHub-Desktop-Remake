#include "command/ConfigCommand.h"

#include "lib/inferlib/printer/Printer.h"
#include "utils/config/ConfigFilenames.h"
#include "utils/status/Status.h"

namespace codehub::utils {

CommandExecutionStatus ConfigCommand::ExecuteImpl(const ParsedCommand& command) {
  using namespace codehub::filesystem;

  if (!ElementExists(GLOBAL_APP_FOLDER_PATH) &&
      !CreateDirectory(GLOBAL_APP_FOLDER_PATH)) {
    return CommandExecutionStatus::RUNTIME_ERROR;
  }

  if (!ElementExists(GLOBAL_APP_CONFIG_PATH) && !CreateFile(GLOBAL_APP_CONFIG_PATH)) {
    return CommandExecutionStatus::RUNTIME_ERROR;
  }

  inferlib::Printer::Println(std::cout, "ConfigCommand is executing!");

  return CommandExecutionStatus::OK;
}

}  // namespace codehub::utils
