#include "command/utils/CommandExecutor.h"

#include "command/utils/CommandsUtils.h"

namespace codehub::utils {

CommandExecutionStatus CommandExecutor::Execute(const ParsedCommand& command) {
  const auto cmd = command::GLOBAL_COMMAND_REGISTRY.At(command.m_keyword);

  return std::visit([&command](auto&& cmd) { return cmd.Execute(command); }, cmd);
}

}  // namespace codehub::utils