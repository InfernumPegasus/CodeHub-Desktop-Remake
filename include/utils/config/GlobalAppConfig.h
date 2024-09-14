#pragma once

#include <string>

#include "utils/parser/ParserUtils.h"

namespace codehub::utils {

/// Отражает ini-файл в секции [GlobalAppConfig].
/// Включает в себя поля 'username' и 'email'
struct GlobalAppConfig {
  static constexpr std::string_view SectionName = "GlobalAppConfig";

  GlobalAppConfig(const std::string& username, const std::string& email);

  GlobalAppConfig() = default;

  [[nodiscard]] const std::string& GetUsername() const;

  [[nodiscard]] const std::string& GetEmail() const;

 private:
  std::string m_username;

  std::string m_email;
};

}  // namespace codehub::utils