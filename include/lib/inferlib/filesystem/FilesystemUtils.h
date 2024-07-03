#pragma once

#include <filesystem>

namespace inferlib::filesystem {

[[nodiscard]] bool FileExists(std::string_view path);

[[nodiscard]] std::filesystem::path GetHomePath();

}  // namespace inferlib::filesystem