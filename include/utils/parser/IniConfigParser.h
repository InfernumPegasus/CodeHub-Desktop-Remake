#pragma once

#include <filesystem>

#include "ParsedIniFile.h"
#include "utils/config/GlobalAppConfig.h"
#include "utils/parser/ParserUtils.h"

namespace codehub::utils {

/// Класс для унифицированного парсинга ini-файлов
struct IniConfigParser {
  struct ParsingPolicy {
    std::string m_comment;
    std::string m_openedSection;
    std::string m_closedSection;
    std::string m_delimiter;
  };

  /// Метод для парсинга ini-файла из считанного файла
  /// \param lines строки считанного файла
  /// \return заполненный объект ini-файла
  [[nodiscard]] static ParsedIniFile Parse(const std::filesystem::path& path,
                                           const ParsingPolicy& policy);
};

}  // namespace codehub::utils