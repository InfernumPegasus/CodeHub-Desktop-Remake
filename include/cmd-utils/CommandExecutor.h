#pragma once

#include <iostream>
#include <variant>

#include "ICommand.h"
#include "lib/inferlib/Printer.h"
#include "utils/ConstexprMap.h"

namespace codehub::utils {

using CommandVariant = std::variant<HelpCommand, AddCommand>;
using CommandRegistry = inferlib::ConstexprVariantMap<std::string_view, CommandVariant>;

class CommandExecutor {
 public:
  explicit CommandExecutor(const CommandRegistry& registry);

  void ExecuteCommand(const ParsedCommand& parsedCommand);

 private:
  const CommandRegistry& m_commandRegistry;
};

}  // namespace codehub::utils
