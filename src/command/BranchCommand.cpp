#include "command/BranchCommand.h"

#include "utils/parser/ParserUtils.h"

namespace codehub::utils {

CommandExecutionStatus BranchCommand::ExecuteImpl(const ParsedCommand& command) {
  return CommandExecutionStatus::OK;
}

}  // namespace codehub::utils