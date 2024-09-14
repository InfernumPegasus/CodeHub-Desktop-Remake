#pragma once

#include <cstdint>
#include <iostream>
#include <string_view>

#include "lib/inferlib/data_structure/ConstexprMap.h"
#include "lib/inferlib/printer/Printer.h"

namespace codehub::utils {

enum class ParserStatus : int8_t {
  OK,
  WRONG_KEYWORD,
  WRONG_FLAG,
  LACK_OF_ARGUMENTS,
};

enum class CommandExecutionStatus : int8_t { OK, LOGIC_ERROR, RUNTIME_ERROR };

static constexpr auto PARSER_STATUS_ERRORS =
    inferlib::MakeConstexprMap<ParserStatus, std::string_view>(
        std::pair{ParserStatus::WRONG_KEYWORD, "Wrong command keyword format"},
        std::pair{ParserStatus::WRONG_FLAG, "Wrong command flag or value format"},
        std::pair{ParserStatus::LACK_OF_ARGUMENTS, "Lack of arguments"});

static constexpr auto COMMAND_EXECUTION_STATUS_ERRORS =
    inferlib::MakeConstexprMap<CommandExecutionStatus, std::string_view>(
        std::pair{CommandExecutionStatus::LOGIC_ERROR, "Logic error"},
        std::pair{CommandExecutionStatus::RUNTIME_ERROR, "Runtime error"});

/// Функция для вывода ошибки по коду парсера
/// \param status ошибка парсера
constexpr void PrintError(ParserStatus status) {
  inferlib::Printer::Println(std::cout, "Parser: ", PARSER_STATUS_ERRORS.At(status));
}

/// Функция для вывода ошибки по коду выполнения команды
/// \param status ошибка выполнения команды
constexpr void PrintError(CommandExecutionStatus status) {
  inferlib::Printer::Println(
      std::cout, "CommandExecutor: ", COMMAND_EXECUTION_STATUS_ERRORS.At(status));
}

}  // namespace codehub::utils
