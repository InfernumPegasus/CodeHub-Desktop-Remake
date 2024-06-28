#pragma once

#include "ICommand.h"

namespace codehub::utils {

struct ConfigCommand : ICommand<ConfigCommand> {
  static constexpr auto AvailableOptions =
      inferlib::MakeConstexprMap<std::string_view, std::string_view>(
          std::pair{"--user", "username"}, std::pair{"--email", "user email"});

  static void ExecuteImpl(const ParsedCommand& command);
};

}  // namespace codehub::utils
