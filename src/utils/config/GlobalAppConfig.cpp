#include "utils/config/GlobalAppConfig.h"

namespace codehub::utils {

std::string_view GlobalAppConfig::GetUsername() const { return m_username; }

std::string_view GlobalAppConfig::GetEmail() const { return m_email; }

GlobalAppConfig::GlobalAppConfig(const std::string& username, const std::string& email)
    : m_username(username), m_email(email) {}

}  // namespace codehub::utils
