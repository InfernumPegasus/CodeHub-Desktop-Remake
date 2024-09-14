#pragma once

#include "utils/parser/ParsedCommand.h"
#include "utils/parser/ParserUtils.h"
#include "utils/status/Status.h"

namespace codehub::utils {

// Класс для выполнения любой доступной команды
class CommandExecutor {
 public:
  /// Выполняет конкретную команду из списка доступных команд
  /// \param command проверенная и готовая к выполнению команда
  /// \return статус выполнения
  [[nodiscard]] static CommandExecutionStatus Execute(const ParsedCommand& command);
};

}  // namespace codehub::utils
