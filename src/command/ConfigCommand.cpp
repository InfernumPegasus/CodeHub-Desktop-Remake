#include "command/ConfigCommand.h"

#include <fstream>

#include "lib/inferlib/printer/Printer.h"
#include "utils/config/ConfigFilenames.h"
#include "utils/config/IniConfigWriter.h"
#include "utils/parser/ParsedCommand.h"
#include "utils/status/Status.h"

namespace codehub::utils {

CommandExecutionStatus ConfigCommand::ExecuteImpl(const ParsedCommand& command) {
  inferlib::Printer::Println(std::cout, "ConfigCommand is executing!");

  GlobalAppConfig config("yui", "vbn");
  if (!WriteGlobalAppConfig(config)) {
    return CommandExecutionStatus::RUNTIME_ERROR;
  }

  return CommandExecutionStatus::OK;
}

bool ConfigCommand::CreateGlobalAppConfig() {
  using namespace codehub::filesystem;

  if (!ElementExists(GLOBAL_APP_FOLDER_PATH) &&
      !CreateDirectory(GLOBAL_APP_FOLDER_PATH)) {
    return false;
  }

  if (!ElementExists(GLOBAL_APP_CONFIG_PATH) && !CreateFile(GLOBAL_APP_CONFIG_PATH)) {
    return false;
  }

  return true;
}

bool ConfigCommand::WriteGlobalAppConfig(const utils::GlobalAppConfig& config) {
  using namespace codehub::filesystem;

  std::ofstream configFile(GLOBAL_APP_CONFIG_PATH);
  if (!configFile.is_open()) {
    return false;
  }

  IniConfigWriter::Write(configFile, config);

  return true;
}

}  // namespace codehub::utils
