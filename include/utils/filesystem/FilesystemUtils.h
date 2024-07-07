#pragma once

#include <filesystem>

namespace codehub::filesystem {

[[nodiscard]] bool FileExists(std::string_view path);

[[nodiscard]] bool FileExists(const std::filesystem::path& path);

[[nodiscard]] std::filesystem::path GetHomePath();

//[[nodiscard]] std::filesystem::path Form

}  // namespace codehub::filesystem