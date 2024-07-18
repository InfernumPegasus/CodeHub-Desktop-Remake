#include "vcs/VCSApplication.h"

#include "command/utils/CommandExecutor.h"
#include "lib/inferlib/printer/Printer.h"
#include "utils/config/ConfigBuilder.h"
#include "utils/config/ConfigFilenames.h"
#include "utils/filesystem/FilesystemUtils.h"
#include "utils/parser/CommandLineParser.h"
#include "utils/parser/IniConfigParser.h"
#include "utils/status/Status.h"
#include "utils/validation/CommandLineParserValidator.h"
#include "utils/validation/IniConfigValidator.h"

namespace codehub {

using namespace utils;
using namespace filesystem;
using namespace inferlib;

VCSApplication::VCSApplication(int argc, char** argv) : m_argc(argc), m_argv(argv) {
  m_command = CommandLineParser::Parse(m_argc, m_argv);

  const auto readFile = ReadTextFile(GLOBAL_APP_CONFIG_PATH);
  const auto parsedFile = IniConfigParser::Parse(readFile);
  m_globalAppConfig = GlobalAppConfigBuilder::Build(parsedFile);
}

void VCSApplication::Init() { CheckConfiguration(); }

void VCSApplication::Run() { CommandExecutor::ExecuteCommand(m_command); }

void VCSApplication::CheckGlobalConfig() {
  //    if (!ElementExists(GLOBAL_APP_FOLDER_PATH)) {
  //      if (!CreateDirectory(GLOBAL_APP_FOLDER_PATH)) {
  //      }
  //    }
  //
  //    if (!ElementExists(GLOBAL_APP_CONFIG_PATH)) {
  //      if (!CreateFile(GLOBAL_APP_CONFIG_PATH)) {
  //      }
  //    }

  static constexpr auto globalConfigValidator =
      ConstructValidatorChain<GlobalAppConfig, ParserStatus>(ValidateGlobalAppConfig);
  if (const auto status = globalConfigValidator.Validate(m_globalAppConfig);
      status != ParserStatus::OK) {
    PrintError(status);
    throw std::runtime_error("CheckGlobalConfig() error");
  }
}

void VCSApplication::CheckConfiguration() {
  CheckGlobalConfig();
  Printer::Println(std::cout, "CheckGlobalConfig() success");

  CheckCommand();
  Printer::Println(std::cout, "CheckCommand() success");
}

void VCSApplication::CheckCommand() {
  static constexpr auto validator = ConstructValidatorChain<ParsedCommand, ParserStatus>(
      ValidateCommandKeyword, ValidateCommandFlags);

  if (auto status = validator.Validate(m_command); status != ParserStatus::OK) {
    PrintError(status);
    throw std::runtime_error("CheckCommand() error");
  }
}

}  // namespace codehub
