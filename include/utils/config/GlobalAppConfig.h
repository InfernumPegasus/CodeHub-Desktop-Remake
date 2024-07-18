#pragma once

#include <string>

#include "utils/parser/ParserUtils.h"

namespace codehub::utils {

/*
 *  Ini file should have section [GlobalAppConfig]
 *  and have valued fields 'username' and 'email'
 */
struct GlobalAppConfig {
  static constexpr std::string_view SectionName = "GlobalAppConfig";

  std::string m_username;

  std::string m_email;
};

}  // namespace codehub::utils