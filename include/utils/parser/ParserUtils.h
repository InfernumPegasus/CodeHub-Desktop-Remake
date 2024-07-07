#pragma once

#include <optional>
#include <ostream>
#include <string_view>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

namespace codehub::utils {

struct ParsedFlagView;
struct ParsedFlag;

using ArgsListView = std::vector<std::string_view>;
using FlagsListView = std::vector<ParsedFlagView>;
using KeyOptValuePairView = std::pair<std::string_view, std::optional<std::string_view>>;

using KeyOptValuePair = std::pair<std::string, std::optional<std::string>>;
using FlagsList = std::vector<ParsedFlag>;
using IniSectionFlagsMap = std::unordered_map<std::string, FlagsList>;

struct ParsedFlagView {
  KeyOptValuePairView m_keyValuePair;

  bool m_shouldHaveValue;
};

struct ParsedFlag {
  KeyOptValuePair m_keyValuePair;

  bool m_shouldHaveValue;
};

struct ParsedCommand {
  std::string_view m_keyword;
  FlagsListView m_flags;
  ArgsListView m_args;

  friend std::ostream& operator<<(std::ostream& os, const ParsedCommand& command);
};

struct ParsedIniFile {
  IniSectionFlagsMap m_sectionFlagsMap;

  friend std::ostream& operator<<(std::ostream& os, const ParsedIniFile& iniFile);
};

}  // namespace codehub::utils
