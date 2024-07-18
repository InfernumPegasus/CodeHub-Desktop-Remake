#include "command/RevertCommand.h"

namespace codehub::utils {

CommandExecutionStatus RevertCommand::ExecuteImpl(const ParsedCommand& command) {
  return CommandExecutionStatus::OK;
}

}  // namespace codehub::utils