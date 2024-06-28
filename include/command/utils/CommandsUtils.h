#pragma once

#include "command/Commands.h"

namespace codehub::utils {

// clang-format off
using CommandVariant = std::variant<
    HelpCommand,
    ConfigCommand,
    InitCommand,
    AddCommand,
    CommitCommand,
    RevertCommand,
    LogCommand,
    VersionCommand,
    BranchCommand,
    CheckoutCommand
>;

static constexpr auto COMMAND_DESCRIPTIONS =
    inferlib::MakeConstexprMap<std::string_view, std::string_view>(
        std::pair{"help", "List of all supported commands"},
        std::pair{"config", "Configure global settings"},
        std::pair{"init", "Init repository"},
        std::pair{"add", "Add file(s), directory(ies) to tracked"},
        std::pair{"commit", "Commit added files"},
        std::pair{"revert", "Revert certain commit"},
        std::pair{"log", "See commit log in branch"},
        std::pair{"version", "Version of software"},
        std::pair{"branch", "Create new branch"},
        std::pair{"checkout", "Change branch"}
);

static constexpr auto GLOBAL_COMMAND_REGISTRY =
    inferlib::MakeConstexprMap<std::string_view, CommandVariant>(
        std::pair{"help", HelpCommand()},
        std::pair{"config", ConfigCommand()},
        std::pair{"init", InitCommand()},
        std::pair{"add", AddCommand()},
        std::pair{"commit", CommitCommand()},
        std::pair{"revert", RevertCommand()},
        std::pair{"log", LogCommand()},
        std::pair{"version", VersionCommand()},
        std::pair{"branch", BranchCommand()},
        std::pair{"checkout", CheckoutCommand()}
    );
// clang-format on

}  // namespace codehub::utils