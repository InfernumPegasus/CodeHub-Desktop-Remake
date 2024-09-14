#pragma once

#include "command/Commands.h"
#include "lib/inferlib/comparison/Comparison.h"
#include "lib/inferlib/data_structure/ConstexprMap.h"

namespace codehub::utils::command {

// clang-format off

// Вариант со всеми поддерживаемыми командами
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

constexpr auto HELP_COMMAND         = "help";
constexpr auto CONFIG_COMMAND       = "config";
constexpr auto INIT_COMMAND         = "init";
constexpr auto ADD_COMMAND          = "add";
constexpr auto COMMIT_COMMAND       = "commit";
constexpr auto REVERT_COMMAND       = "revert";
constexpr auto LOG_COMMAND          = "log";
constexpr auto VERSION_COMMAND      = "version";
constexpr auto BRANCH_COMMAND       = "branch";
constexpr auto CHECKOUT_COMMAND     = "checkout";

constexpr auto HELP_DESCRIPTION     = "List of all supported commands";
constexpr auto CONFIG_DESCRIPTION   = "Configure global settings";
constexpr auto INIT_DESCRIPTION     = "Init repository";
constexpr auto ADD_DESCRIPTION      = "Add file(s), directory(ies) to tracked";
constexpr auto COMMIT_DESCRIPTION   = "Commit added files";
constexpr auto REVERT_DESCRIPTION   = "Revert certain commit";
constexpr auto LOG_DESCRIPTION      = "See commit log in branch";
constexpr auto VERSION_DESCRIPTION  = "Version of software";
constexpr auto BRANCH_DESCRIPTION   = "Create new branch";
constexpr auto CHECKOUT_DESCRIPTION = "Change branch";

static constexpr auto COMMAND_DESCRIPTIONS =
    inferlib::MakeConstexprMap<std::string_view, std::string_view>(
        std::pair{HELP_COMMAND, HELP_DESCRIPTION},
        std::pair{CONFIG_COMMAND, CONFIG_DESCRIPTION},
        std::pair{INIT_COMMAND, INIT_DESCRIPTION},
        std::pair{ADD_COMMAND, ADD_DESCRIPTION},
        std::pair{COMMIT_COMMAND, COMMIT_DESCRIPTION},
        std::pair{REVERT_COMMAND, REVERT_DESCRIPTION},
        std::pair{LOG_COMMAND, LOG_DESCRIPTION},
        std::pair{VERSION_COMMAND, VERSION_DESCRIPTION},
        std::pair{BRANCH_COMMAND, BRANCH_DESCRIPTION},
        std::pair{CHECKOUT_COMMAND, CHECKOUT_DESCRIPTION}
);

static constexpr auto GLOBAL_COMMAND_REGISTRY =
    inferlib::MakeConstexprMap<std::string_view, CommandVariant>(
        std::pair{HELP_COMMAND, HelpCommand()},
        std::pair{CONFIG_COMMAND, ConfigCommand()},
        std::pair{INIT_COMMAND, InitCommand()},
        std::pair{ADD_COMMAND, AddCommand()},
        std::pair{COMMIT_COMMAND, CommitCommand()},
        std::pair{REVERT_COMMAND, RevertCommand()},
        std::pair{LOG_COMMAND, LogCommand()},
        std::pair{VERSION_COMMAND, VersionCommand()},
        std::pair{BRANCH_COMMAND, BranchCommand()},
        std::pair{CHECKOUT_COMMAND, CheckoutCommand()}
    );
// clang-format on

// Проверка на равенство количества команд и их описаний
static_assert(inferlib::AllEqual(GLOBAL_COMMAND_REGISTRY.data.size(),
                                 COMMAND_DESCRIPTIONS.data.size(),
                                 std::variant_size_v<CommandVariant>),
              "CommandVariant, GLOBAL_COMMAND_DESCRIPTIONS and GLOBAL_COMMAND_REGISTRY "
              "sizes are not equal");

// Проверка на соответствие имен команд и их описаний
static_assert(
    inferlib::AllEqual(ExtractKeys(GLOBAL_COMMAND_REGISTRY),
                       ExtractKeys(COMMAND_DESCRIPTIONS)),
    "GLOBAL_COMMAND_REGISTRY and GLOBAL_COMMAND_DESCRIPTIONS keys are not equal");

}  // namespace codehub::utils::command