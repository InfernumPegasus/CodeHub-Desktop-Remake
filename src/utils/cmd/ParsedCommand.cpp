#include "utils/cmd/ParsedCommand.h"

namespace codehub::utils {

std::ostream& operator<<(std::ostream& os, const ParsedCommand& command) {
  os << "Keyword: " << command.m_keyword << "\nFlags and their arguments:\n";
  for (const auto& [flag, hasValue] : command.m_flags) {
    os << "Command flag: " << flag.first;
    if (hasValue && !flag.second->empty()) {
      os << " | Argument: " << flag.second.value();
    }
    os << '\n';
  }

  os << "Simple arguments: ";
  for (const auto& arg : command.m_args) {
    os << arg << ' ';
  }

  return os;
}

}  // namespace codehub::utils
