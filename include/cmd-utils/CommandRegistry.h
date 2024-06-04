#pragma once

#include <functional>
#include <memory>
#include <string_view>
#include <unordered_map>

#include "ICommand.h"

namespace codehub::utils {

class CommandRegistry {
 public:
  using ICommandPtr = std::shared_ptr<codehub::utils::ICommand>;

  void RegisterCommand(std::string_view name, ICommandPtr&& command);

  ICommandPtr GetCommand(std::string_view name) const;

 private:
  std::unordered_map<std::string_view, ICommandPtr> m_commands;
};

}  // namespace codehub::utils
