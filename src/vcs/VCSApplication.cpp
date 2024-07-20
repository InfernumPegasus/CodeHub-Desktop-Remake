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

void VCSApplication::Run() {
  if (const auto status = CommandExecutor::Execute(m_command);
      status != CommandExecutionStatus::OK) {
    PrintError(status);
    std::exit(3);
  }
}

void VCSApplication::CheckConfiguration() {
  if (const auto status = CheckGlobalConfig(); status != ParserStatus::OK) {
    Printer::Println(std::cout,
                     "CheckGlobalConfig() error. Please check your config or use 'config "
                     "--init' command");
    PrintError(status);
    std::exit(1);
  }

  if (const auto status = CheckCommand(); status != ParserStatus::OK) {
    Printer::Println(
        std::cout,
        "CheckCommand() error. Please check your command or use 'help' command");
    PrintError(status);
    std::exit(2);
  }
}

utils::ParserStatus VCSApplication::CheckGlobalConfig() {
  static constexpr auto globalConfigValidator =
      ConstructValidatorChain<GlobalAppConfig, ParserStatus>(ValidateGlobalAppConfig);
  return globalConfigValidator.Validate(m_globalAppConfig);
}

utils::ParserStatus VCSApplication::CheckCommand() {
  static constexpr auto validator = ConstructValidatorChain<ParsedCommand, ParserStatus>(
      ValidateCommandKeyword, ValidateCommandFlags);
  return validator.Validate(m_command);
}

}  // namespace codehub
