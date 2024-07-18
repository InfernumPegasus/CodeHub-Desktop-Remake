#pragma once

#include "GlobalAppConfig.h"
#include "utils/parser/ParsedIniFile.h"
#include "utils/parser/ParserUtils.h"

namespace codehub::utils {

template <class Config, class Builder>
struct ConfigBuilder {
  static Config Build(const ParsedIniFile& validatedIniFile) {
    return Builder::Build(validatedIniFile);
  }
};

struct GlobalAppConfigBuilder : ConfigBuilder<GlobalAppConfig, GlobalAppConfigBuilder> {
  static GlobalAppConfig Build(const ParsedIniFile& validatedIniFile) {
    const auto userName =
        validatedIniFile.GetFlagFromSection(GlobalAppConfig::SectionName, "username")
            ->m_keyValuePair.second.value_or("");
    const auto email =
        validatedIniFile.GetFlagFromSection(GlobalAppConfig::SectionName, "email")
            ->m_keyValuePair.second.value_or("");

    return {userName, email};
  }
};

}  // namespace codehub::utils
