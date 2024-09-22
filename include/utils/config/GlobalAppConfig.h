#pragma once

#include <string>

#include "utils/parser/ParserUtils.h"

namespace codehub::utils {

/// Отражает ini-файл в секции [GlobalAppConfig].
/// Включает в себя поля 'username' и 'email'
class GlobalAppConfig {
 public:
  static constexpr std::string_view SectionName = "GlobalAppConfig";

  GlobalAppConfig(const std::string& username, const std::string& email);

  constexpr GlobalAppConfig() = default;

  [[nodiscard]] std::string_view GetUsername() const;

  [[nodiscard]] std::string_view GetEmail() const;

 private:
  std::string m_username;

  std::string m_email;
};

}  // namespace codehub::utils