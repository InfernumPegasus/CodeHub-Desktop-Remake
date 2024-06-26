#include "command/utils/CommandExecutor.h"

#include "command/utils/CommandsUtils.h"

namespace codehub::utils {

void CommandExecutor::ExecuteCommand(const ParsedCommand& command) {
  const auto cmd = GLOBAL_COMMAND_REGISTRY.At(command.m_keyword);
  std::visit([&command](auto&& cmd) { cmd.Execute(command); }, cmd);
}

}  // namespace codehub::utils