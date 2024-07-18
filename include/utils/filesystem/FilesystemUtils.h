#pragma once

#include <filesystem>
#include <vector>

namespace codehub::filesystem {

[[nodiscard]] bool ElementExists(const std::filesystem::path& path);

[[nodiscard]] std::filesystem::path GetHomePath();

[[nodiscard]] std::vector<std::string> ReadTextFile(const std::filesystem::path& path);

bool CreateFile(const std::filesystem::path& path);

bool CreateDirectory(const std::filesystem::path& path);

}  // namespace codehub::filesystem