#pragma once

#include <iostream>
#include <variant>

#include "lib/inferlib/data_structure/ConstexprMap.h"
#include "utils/parser/ParsedCommand.h"
#include "utils/status/Status.h"

namespace codehub::utils {

/// Общий класс команды. Все актуальные команды должны наследоваться от него
/// \tparam Impl тип реализуемой команды
template <typename Impl>
struct ICommand {
  /// Метод для выполнения команды. Задействует статический метод ExecuteImpl переданной
  /// команды
  /// \param command команда для выполнения
  /// \return статус выполнения команды
  static constexpr CommandExecutionStatus Execute(const ParsedCommand& command) {
    return Impl::ExecuteImpl(command);
  }
};

}  // namespace codehub::utils
