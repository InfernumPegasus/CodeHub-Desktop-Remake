#pragma once

#include <filesystem>

#include "ParsedIniFile.h"
#include "utils/config/GlobalAppConfig.h"
#include "utils/parser/ParserUtils.h"

namespace codehub::utils {

/// Класс для унифицированного парсинга ini-файлов
struct IniConfigParser {
  static constexpr char32_t COMMENT_SYMBOL = U';';

  static constexpr char32_t OPEN_SECTION_SYMBOL = U'[';

  static constexpr char32_t CLOSE_SECTION_SYMBOL = U']';

  static constexpr char32_t VALUE_DELIMITER_SYMBOL = U'=';

  /// Метод для парсинга ini-файла из считанного файла
  /// \param lines строки считанного файла
  /// \return заполненный объект ini-файла
  [[nodiscard]] static ParsedIniFile Parse(const std::vector<std::string>& lines);
};

}  // namespace codehub::utils