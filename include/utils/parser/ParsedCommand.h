#pragma once

#include "ParserUtils.h"

namespace codehub::utils {

struct ParsedCommand {
  std::string_view m_keyword;
  FlagsListView m_flags;
  ArgsListView m_args;

  friend std::ostream& operator<<(std::ostream& os, const ParsedCommand& command);
};

}
