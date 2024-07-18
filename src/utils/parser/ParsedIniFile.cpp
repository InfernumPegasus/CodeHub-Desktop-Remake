#include "utils/parser/ParsedIniFile.h"

#include <algorithm>

namespace codehub::utils {

ParsedIniFile::ParsedIniFile(IniSectionFlagsMap sectionFlagsMap)
    : m_sectionFlagsMap(std::move(sectionFlagsMap)) {}

std::optional<FlagsList> ParsedIniFile::GetSectionFlags(std::string_view section) const {
  const auto found = m_sectionFlagsMap.find(section.data());
  if (found != m_sectionFlagsMap.cend()) {
    return std::make_optional(found->second);
  }
  return std::nullopt;
}

std::optional<ParsedFlag> ParsedIniFile::GetFlagFromSection(
    std::string_view section, std::string_view flagName) const {
  return GetSectionFlags(section).and_then(
      [&flagName](const FlagsList& flags) -> std::optional<ParsedFlag> {
        auto it =
            std::find_if(flags.begin(), flags.end(), [&flagName](const ParsedFlag& flag) {
              return flag.m_keyValuePair.first == flagName;
            });
        if (it != flags.end()) {
          return std::make_optional(*it);
        }
        return std::nullopt;
      });
}

IniSectionFlagsMap ParsedIniFile::GetSectionFlags() const { return m_sectionFlagsMap; }

std::ostream& operator<<(std::ostream& os, const ParsedIniFile& iniFile) {
  for (const auto& [section, flags] : iniFile.m_sectionFlagsMap) {
    os << "[" << section << "]\n";
    for (const auto& flag : flags) {
      os << "  " << flag.m_keyValuePair.first;
      if (flag.m_keyValuePair.second) {
        os << "=" << *flag.m_keyValuePair.second;
      }
      os << "\n";
    }
  }

  return os;
}

}  // namespace codehub::utils
