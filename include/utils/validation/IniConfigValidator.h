#pragma once

#include "ValidatorChain.h"
#include "utils/parser/ParsedIniFile.h"
#include "utils/parser/ParserUtils.h"
#include "utils/status/Status.h"

namespace codehub::utils {

constexpr auto ValidateGlobalAppConfig =
    [](const GlobalAppConfig& config) -> ValidatorResult<GlobalAppConfig, ParserStatus> {
  if (config.GetUsername().empty() || config.GetEmail().empty()) {
    return {ParserStatus::LACK_OF_ARGUMENTS, "'username' or 'email' fields not provided"};
  }
  return {ParserStatus::OK, ""};
};

}  // namespace codehub::utils