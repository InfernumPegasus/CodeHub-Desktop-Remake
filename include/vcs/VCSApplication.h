#pragma once

#include "utils/config/GlobalAppConfig.h"
#include "utils/parser/ParsedCommand.h"

namespace codehub {

class VCSApplication {
 public:
  VCSApplication(int argc, char** argv);

  void Init();

  void Run();

 private:
  void CheckGlobalConfig();

  void CheckConfiguration();

  void CheckCommand();

 private:
  int m_argc;
  char** m_argv;

  utils::ParsedCommand m_command;
  utils::GlobalAppConfig m_globalAppConfig;
};

}  // namespace codehub
