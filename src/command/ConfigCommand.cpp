#include "command/ConfigCommand.h"

#include "lib/inferlib/printer/Printer.h"
#include "utils/config/ConfigFilenames.h"
#include "utils/config/GlobalAppConfig.h"
#include "utils/filesystem/FilesystemUtils.h"

namespace codehub::utils {

void ConfigCommand::ExecuteImpl(const ParsedCommand& command) {
  using namespace codehub::filesystem;

  const auto globalAppFolderPath = HOME_PATH / GLOBAL_APP_FOLDER;
  inferlib::Printer::Println(std::cout, "globalAppFolderPath:", globalAppFolderPath);

  if (FileExists(globalAppFolderPath)) {
    inferlib::Printer::Println(std::cout, "global app folder exists");


  }
}

}  // namespace codehub::utils
