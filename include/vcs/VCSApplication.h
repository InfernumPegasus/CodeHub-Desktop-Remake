#pragma once

#include "utils/config/GlobalAppConfig.h"
#include "utils/parser/ParsedCommand.h"
#include "utils/status/Status.h"

namespace codehub {

class VCSApplication {
 public:
  VCSApplication(int argc, char** argv);

  void Init();

  void Run();

 private:
  void CheckConfiguration();

  utils::ParserStatus CheckGlobalConfig();

  utils::ParserStatus CheckCommand();

 private:
  int m_argc;
  char** m_argv;

  utils::ParsedCommand m_command;
  utils::GlobalAppConfig m_globalAppConfig;
};

}  // namespace codehub
