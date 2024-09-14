#pragma once

#include "ParserUtils.h"

namespace codehub::utils {

/// Класс, представляющий ini-файл
class ParsedIniFile {
 public:

  /// Конструктор класса
  /// \param sectionFlagsMap объект, содержащий секции и их флаги
  explicit ParsedIniFile(IniSectionFlagsMap sectionFlagsMap);

  /// Метод для получения всех флагов из определенной секции
  /// \param section имя секции
  /// \return массив флагов из секции
  std::optional<FlagsList> GetSectionFlags(std::string_view section) const;

  /// Метод для получения значения флага в секции
  /// \param section имя секции
  /// \param flagName имя флага
  /// \return std::optional с флагом
  std::optional<ParsedFlag> GetFlagFromSection(std::string_view section,
                                               std::string_view flagName) const;

  /// Метод для получения всех флагов и секций
  /// \return все флаги всех секций
  IniSectionFlagsMap GetSectionFlags() const;

  /// Перегруженный оператор вывода
  /// \param os поток вывода
  /// \param iniFile объект
  /// \return поток вывода
  friend std::ostream& operator<<(std::ostream& os, const ParsedIniFile& iniFile);

 private:
  IniSectionFlagsMap m_sectionFlagsMap;
};

}  // namespace codehub::utils