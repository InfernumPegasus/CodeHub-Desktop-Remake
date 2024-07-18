#pragma once

#include <filesystem>
#include <string_view>

#include "utils/filesystem/FilesystemUtils.h"

namespace codehub::filesystem {

static const std::filesystem::path HOME_PATH = GetHomePath();

static constexpr std::string_view GLOBAL_APP_FOLDER = "CodeHubR";

static constexpr std::string_view GLOBAL_APP_CONFIG = ".chglobalconfig";

static constexpr std::string_view IGNORE_FILE_NAME = ".chignore";

static constexpr std::string_view REPOSITORY_FOLDER_NAME = ".chrepo";

static const auto GLOBAL_APP_FOLDER_PATH = HOME_PATH / GLOBAL_APP_FOLDER;

static const auto GLOBAL_APP_CONFIG_PATH = GLOBAL_APP_FOLDER_PATH / GLOBAL_APP_CONFIG;

}  // namespace codehub::filesystem