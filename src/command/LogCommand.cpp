#include "command/LogCommand.h"

namespace codehub::utils {

CommandExecutionStatus LogCommand::ExecuteImpl(const ParsedCommand& command) {
  return CommandExecutionStatus::OK;
}

}  // namespace codehub::utils