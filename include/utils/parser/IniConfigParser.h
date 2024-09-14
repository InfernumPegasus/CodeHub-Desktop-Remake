#pragma once

#include <filesystem>

#include "ParsedIniFile.h"
#include "utils/config/GlobalAppConfig.h"
#include "utils/parser/ParserUtils.h"

namespace codehub::utils {

/// Класс для унифицированного парсинга ini-файлов
struct IniConfigParser {

  /// Метод для парсинга ini-файла из считанного файла
  /// \param lines строки считанного файла
  /// \return готовый объект ini-файла
  [[nodiscard]] static ParsedIniFile Parse(const std::vector<std::string>& lines);
};

}  // namespace codehub::utils