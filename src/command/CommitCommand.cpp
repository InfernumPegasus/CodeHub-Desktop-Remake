#include "command/CommitCommand.h"

namespace codehub::utils {

CommandExecutionStatus CommitCommand::ExecuteImpl(const ParsedCommand& command) {
  return CommandExecutionStatus::OK;
}

}  // namespace codehub::utils