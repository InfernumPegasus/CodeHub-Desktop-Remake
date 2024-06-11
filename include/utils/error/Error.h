#pragma once

#include <iostream>
#include <string_view>

#include "lib/inferlib/ConstexprMap.h"
#include "lib/inferlib/Printer.h"

namespace codehub::utils {

enum class ParserStatus : int8_t {
  OK,
  WRONG_KEYWORD,
  WRONG_FLAG,
  LACK_OF_ARGUMENTS,
};

static constexpr auto PARSER_STATUS_ERRORS =
    inferlib::MakeConstexprMap<ParserStatus, std::string_view>(
        std::pair{ParserStatus::WRONG_KEYWORD, "Error: Wrong command keyword format"},
        std::pair{ParserStatus::WRONG_FLAG, "Error: Wrong command flag or value format"},
        std::pair{ParserStatus::LACK_OF_ARGUMENTS, "Error: Lack of arguments"});

constexpr void PrintError(ParserStatus status) {
  inferlib::Printer::Println(std::cerr, PARSER_STATUS_ERRORS.At(status));
}

}  // namespace codehub::utils
