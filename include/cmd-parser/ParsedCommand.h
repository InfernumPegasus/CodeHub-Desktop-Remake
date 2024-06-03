#pragma once

#include <optional>
#include <ostream>
#include <string_view>
#include <utility>
#include <vector>

namespace codehub::utils {

struct ParsedCommandFlag;

using CommandArgsList = std::vector<std::string_view>;
using CommandFlagsList = std::vector<ParsedCommandFlag>;
using KeyOptValuePair = std::pair<std::string_view, std::optional<std::string_view>>;

struct ParsedCommandFlag {
  KeyOptValuePair m_keyValuePair;

  bool m_shouldHaveValue;
};

struct ParsedCommand {
  std::string_view m_keyword;
  CommandFlagsList m_flags;
  CommandArgsList m_args;

  friend std::ostream& operator<<(std::ostream& os, const ParsedCommand& command);
};

}  // namespace codehub::utils
