#include "utils/parser/IniConfigParser.h"

#include <algorithm>
#include <fstream>

#include "utils/filesystem/FilesystemUtils.h"

namespace codehub::utils {

ParsedIniFile IniConfigParser::Parse(const std::filesystem::path& path,
                                     const ParsingPolicy& policy) {
  IniSectionFlagsMap iniMap;
  std::string currentSection;

  const std::vector<std::string> lines = filesystem::ReadTextFile(path);

  for (const auto& line : lines) {
    if (line.empty() || line.starts_with(policy.m_comment)) {
      continue;
    }

    if (line.starts_with(policy.m_openedSection) &&
        line.ends_with(policy.m_closedSection)) {
      currentSection = line.substr(
          policy.m_openedSection.size(),
          line.size() - policy.m_openedSection.size() - policy.m_closedSection.size());
      iniMap[currentSection] = FlagsList();
      continue;
    }

    const auto pos = line.find(policy.m_delimiter);
    if (pos != std::string::npos) {
      const auto key = line.substr(0, pos);
      auto value = line.substr(pos + policy.m_delimiter.size());
      const bool shouldHaveValue = !value.empty();

      const auto commentPos = value.find(policy.m_comment);
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
