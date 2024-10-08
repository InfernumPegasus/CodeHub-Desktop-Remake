#pragma once

#include "ICommand.h"
#include "utils/config/GlobalAppConfig.h"

namespace codehub::utils {

struct ConfigCommand : ICommand<ConfigCommand> {
  // clang-format off
  static constexpr auto AvailableOptions =
      inferlib::MakeConstexprMap<std::string_view, std::string_view>(
          std::pair{"--user", "user name"},
          std::pair{"--email", "user email"}
      );
  // clang-format on

  static CommandExecutionStatus ExecuteImpl(const ParsedCommand& command);

  static bool CreateGlobalAppConfig();

  static bool WriteGlobalAppConfig(const utils::GlobalAppConfig& config);
};

}  // namespace codehub::utils
