#include "utils/parser/IniConfigParser.h"

#include <algorithm>
#include <fstream>

namespace codehub::utils {

ParsedIniFile IniConfigParser::Parse(const std::vector<std::string>& lines) {
  IniSectionFlagsMap iniMap;
  std::string currentSection;

  for (const auto& line : lines) {
    if (line.empty() || line.front() == COMMENT_SYMBOL) {
      continue;
    }

    if (line.front() == OPEN_SECTION_SYMBOL && line.back() == CLOSE_SECTION_SYMBOL) {
      currentSection = line.substr(1, line.size() - 2);
      iniMap[currentSection] = FlagsList();
      continue;
    }

    const auto pos = line.find(VALUE_DELIMITER_SYMBOL);
    if (pos != std::string::npos) {
      const auto key = line.substr(0, pos);
      auto value = line.substr(pos + 1);
      const bool shouldHaveValue = !value.empty();

      const auto commentPos = value.find(COMMENT_SYMBOL);
      if (commentPos != std::string::npos) {
        value = value.substr(0, commentPos);
      }

      const ParsedFlag flag{
          {key, shouldHaveValue ? std::make_optional<std::string>(value) : std::nullopt},
          shouldHaveValue};
      iniMap[currentSection].push_back(flag);
    }
  }

  ParsedIniFile file(iniMap);
  return file;
}

}  // namespace codehub::utils
