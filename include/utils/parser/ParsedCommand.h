#pragma once

#include "ParserUtils.h"

namespace codehub::utils {

/// Класс распаршенной команды с ключевым словом, флагами и их параметрами
/// и простыми аргументами
struct ParsedCommand {
  std::string_view m_keyword;
  FlagsListView m_flags;
  ArgsListView m_args;
};

}
