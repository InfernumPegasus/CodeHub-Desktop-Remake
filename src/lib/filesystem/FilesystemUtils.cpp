#include "lib/inferlib/filesystem/FilesystemUtils.h"

namespace inferlib::filesystem {

bool FileExists(std::string_view path) { return std::filesystem::exists(path); }

std::filesystem::path GetHomePath() {
#if defined(_WIN32) || defined(_WIN64)
  const auto homeDrive = std::getenv("HOMEDRIVE");
  const auto homePath = std::getenv("HOMEPATH");
  if (homeDrive && homePath) {
    return std::filesystem::path(homeDrive) / homePath;
  }
#else
  const auto home = std::getenv("HOME");
  if (home) {
    return home;
  }
#endif

  throw std::logic_error("HOME path cannot be determined");
}
}  // namespace inferlib::filesystem
