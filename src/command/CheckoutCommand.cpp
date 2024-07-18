#include "command/CheckoutCommand.h"

namespace codehub::utils {

CommandExecutionStatus CheckoutCommand::ExecuteImpl(const ParsedCommand& command) {
  return CommandExecutionStatus::OK;
}

}  // namespace codehub::utils