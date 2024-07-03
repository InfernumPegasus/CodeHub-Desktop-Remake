#pragma once

#include <filesystem>
#include <string_view>

#include "lib/inferlib/filesystem/FilesystemUtils.h"

namespace codehub::config {

static const std::filesystem::path HOME_PATH = inferlib::filesystem::GetHomePath();

static constexpr std::string_view GLOBAL_APP_FOLDER = "CodeHubR";

static constexpr std::string_view IGNORE_FILE_NAME = ".chignore";

static constexpr std::string_view REPOSITORY_FOLDER_NAME = ".chrepo";

}  // namespace codehub::config