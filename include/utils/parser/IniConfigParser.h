#pragma once

#include <filesystem>

#include "utils/config/GlobalAppConfig.h"
#include "utils/parser/ParserUtils.h"

namespace codehub::utils {

struct IniConfigParser {
  [[nodiscard]] static ParsedIniFile Parse(const std::vector<std::string>& lines);
};

}  // namespace codehub::utils