#include "command/AddCommand.h"

namespace codehub::utils {

CommandExecutionStatus AddCommand::ExecuteImpl(const ParsedCommand& command) {
  return CommandExecutionStatus::OK;
}

}  // namespace codehub::utils