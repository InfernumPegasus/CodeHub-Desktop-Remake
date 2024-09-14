#pragma once

#include "GlobalAppConfig.h"
#include "utils/parser/ParsedIniFile.h"
#include "utils/parser/ParserUtils.h"

namespace codehub::utils {

/// Класс-строитель ini-конфигов
/// \tparam Config тип создаваемого конфига
/// \tparam Builder тип строителя когфига
template <class Config, class Builder>
struct ConfigBuilder {
  /// Метод для построения конфига из подготовленного ini-файла
  /// \param parsedIniFile подготовленный ini-файл
  /// \return конфиг типа Config
  static constexpr Config Build(const ParsedIniFile& parsedIniFile) {
    return Builder::Build(parsedIniFile);
  }
};

/// Специализированный класс строителя для конфига типа GlobalAppConfig
struct GlobalAppConfigBuilder : ConfigBuilder<GlobalAppConfig, GlobalAppConfigBuilder> {
  /// Реализация построения конфига
  /// \param parsedIniFile подготовленный ini-файл
  /// \return конфиг типа GlobalAppConfig
  static constexpr GlobalAppConfig Build(const ParsedIniFile& parsedIniFile) {
    const auto userName =
        parsedIniFile.GetFlagFromSection(GlobalAppConfig::SectionName, "username")
            ->m_keyValuePair.second.value_or("");
    const auto email =
        parsedIniFile.GetFlagFromSection(GlobalAppConfig::SectionName, "email")
            ->m_keyValuePair.second.value_or("");

    return {userName, email};
  }
};

}  // namespace codehub::utils
