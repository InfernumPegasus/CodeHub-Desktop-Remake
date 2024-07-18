#include "utils/filesystem/FilesystemUtils.h"

#include <fstream>
#include <iostream>

#define DEBUG 1

namespace codehub::filesystem {

bool ElementExists(const std::filesystem::path& path) {
  return std::filesystem::exists(path);
}

std::filesystem::path GetHomePath() {
#if DEBUG == 1
  return std::filesystem::current_path();
#endif

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

std::vector<std::string> ReadTextFile(const std::filesystem::path& path) {
  std::vector<std::string> res;

  std::ifstream ifs(path);
  if (ifs) {
    std::string line;
    while (std::getline(ifs, line)) {
      res.push_back(line);
    }
  }

  return res;
}

bool CreateFile(const std::filesystem::path& path) {
  std::ofstream ofs(path);
  return ofs.is_open();
}

bool CreateDirectory(const std::filesystem::path& path) {
  return std::filesystem::create_directory(path);
}

}  // namespace codehub::filesystem
