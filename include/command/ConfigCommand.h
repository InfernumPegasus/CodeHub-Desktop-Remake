#pragma once

#include "ICommand.h"

namespace codehub::utils {

struct ConfigCommand : ICommand<ConfigCommand> {
  // clang-format off
  static constexpr auto AvailableOptions =
      inferlib::MakeConstexprMap<std::string_view, std::string_view>(
          std::pair{"--user", "user name"},
          std::pair{"--email", "user email"}
      );
  // clang-format on

  static void ExecuteImpl(const ParsedCommand& command);
};

}  // namespace codehub::utils
