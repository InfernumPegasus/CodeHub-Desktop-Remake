#pragma once

#include "ValidatorChain.h"
#include "utils/parser/ParsedIniFile.h"
#include "utils/parser/ParserUtils.h"
#include "utils/status/Status.h"

namespace codehub::utils {

constexpr auto ValidateGlobalAppConfig =
    [](const GlobalAppConfig& config) -> ValidatorResult<GlobalAppConfig, ParserStatus> {
  if (config.m_username.empty() || config.m_email.empty()) {
    return {ParserStatus::LACK_OF_ARGUMENTS, "'username' or 'email' fields not provided"};
  }
  return {ParserStatus::OK};
};

}  // namespace codehub::utils