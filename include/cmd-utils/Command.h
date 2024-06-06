#pragma once

#include <concepts>
#include <iostream>
#include <variant>

#include "ParsedCommand.h"
#include "utils/ConstexprMap.h"

namespace codehub::utils {

template <typename Impl>
struct Command {
  static void Execute(const ParsedCommand& command) { Impl::ExecuteImpl(command); }
};

struct HelpCommand : Command<HelpCommand> {
  static void ExecuteImpl(const ParsedCommand& command) { std::cout << "Help command\n"; }
};

struct AddCommand : Command<AddCommand> {
  static void ExecuteImpl(const ParsedCommand& command) { std::cout << "Add command\n"; }
};

struct VersionCommand : Command<VersionCommand> {
  static void ExecuteImpl(const ParsedCommand& command) {
    std::cout << "Version command\n";
  }
};

using CommandVariant = std::variant<HelpCommand, AddCommand, VersionCommand>;
using CommandRegistry = inferlib::ConstexprVariantMap<std::string_view, CommandVariant>;

static constexpr std::array<std::pair<std::string_view, CommandVariant>,
                            std::variant_size_v<CommandVariant>>
    commands{{
        {"help", HelpCommand()},
        {"add", AddCommand()},
        {"version", VersionCommand()},
    }};

static constexpr CommandRegistry GLOBAL_COMMAND_REGISTRY{{commands}};

}  // namespace codehub::utils
