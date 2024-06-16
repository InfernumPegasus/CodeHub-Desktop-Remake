#pragma once

#include <string_view>

namespace codehub::utils {

struct GlobalAppConfig {
  std::string m_username;

  std::string m_email;
};

}  // namespace codehub::utils