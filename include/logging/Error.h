#pragma once

#include <iostream>
#include <string_view>
#include <unordered_map>

#include "lib/inferlib/ConstexprMap.h"
#include "lib/inferlib/Printer.h"

namespace codehub::utils {

enum class ParserStatus : int8_t {
  OK,
  WRONG_KEYWORD,
  WRONG_FLAG,
  LACK_OF_ARGUMENTS,
};

template <typename T>
static constexpr void PrintError(T) = delete;

static constexpr void PrintError(ParserStatus status) {
  using namespace std::string_view_literals;

  static constexpr auto parserStatusMessages =
      inferlib::MakeConstexprMap<ParserStatus, std::string_view>(
          std::pair{ParserStatus::WRONG_KEYWORD, "Error: Wrong command keyword format"sv},
          std::pair{ParserStatus::WRONG_FLAG,
                    "Error: Wrong command flag or value format"sv},
          std::pair{ParserStatus::LACK_OF_ARGUMENTS, "Error: Lack of arguments"sv});

  inferlib::Printer::Println(std::cerr, parserStatusMessages.At(status));
}

}  // namespace codehub::utils
