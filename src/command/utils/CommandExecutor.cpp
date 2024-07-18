#include "command/utils/CommandExecutor.h"

#include "command/utils/CommandsUtils.h"

namespace codehub::utils {

void CommandExecutor::ExecuteCommand(const ParsedCommand& command) {
  const auto cmd = command::GLOBAL_COMMAND_REGISTRY.At(command.m_keyword);
  [[maybe_unused]] const auto res =
      std::visit([&command](auto&& cmd) { return cmd.Execute(command); }, cmd);
}

}  // namespace codehub::utils