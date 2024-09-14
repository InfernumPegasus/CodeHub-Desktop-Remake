#pragma once

#include <iostream>

#include "GlobalAppConfig.h"
#include "lib/inferlib/printer/Printer.h"

namespace codehub::utils {

/// Класс для записи данных в формате ini
/// \tparam Config выходной поток. Должен иметь перегруженный оператор вывода
struct IniConfigWriter {
  template <typename OStream>
  static void Write(OStream& os, const GlobalAppConfig& config) {
    using namespace inferlib;
    Printer::Println(os, '[', GlobalAppConfig::SectionName, ']');
    Printer::Println(os, "username", '=', config.GetUsername());
    Printer::Println(os, "email", '=', config.GetEmail());
  }
};

}  // namespace codehub::utils
