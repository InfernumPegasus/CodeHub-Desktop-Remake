#include "command/InitCommand.h"

namespace codehub::utils {

CommandExecutionStatus InitCommand::ExecuteImpl(const ParsedCommand& command) {
  return CommandExecutionStatus::OK;
}

}  // namespace codehub::utils