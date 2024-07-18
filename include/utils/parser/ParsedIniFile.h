#pragma once

#include "ParserUtils.h"

namespace codehub::utils {

class ParsedIniFile {
 public:
  explicit ParsedIniFile(IniSectionFlagsMap sectionFlagsMap);

  std::optional<FlagsList> GetSectionFlags(std::string_view section) const;

  std::optional<ParsedFlag> GetFlagFromSection(std::string_view section,
                                               std::string_view flagName) const;

  IniSectionFlagsMap GetSectionFlags() const;

  friend std::ostream& operator<<(std::ostream& os, const ParsedIniFile& iniFile);

 private:
  IniSectionFlagsMap m_sectionFlagsMap;
};

}  // namespace codehub::utils