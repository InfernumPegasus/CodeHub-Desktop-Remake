#pragma once

#include <array>
#include <string>

namespace codehub::utils {

template <typename, typename Status>
struct ValidatorResult {
  Status status;
  std::string errorMessage;
};

template <typename Object, typename Status>
using ValidatorFunction = ValidatorResult<Object, Status> (*)(const Object&);

template <typename Object, typename Status, std::size_t N>
class ValidatorChain {
 public:
  constexpr explicit ValidatorChain(
      std::array<ValidatorFunction<Object, Status>, N> validators)
      : validators_(std::move(validators)) {}

  [[nodiscard]] constexpr Status Validate(const Object& obj) const {
    for (auto validator : validators_) {
      auto result = validator(obj);
      if (result.status != Status::OK) {
        return result.status;
      }
    }
    return Status::OK;
  }

 private:
  std::array<ValidatorFunction<Object, Status>, N> validators_;
};

template <typename Object, typename Status, typename... Validators>
[[nodiscard]] constexpr auto ConstructValidatorChain(Validators... validators) {
  return ValidatorChain<Object, Status, sizeof...(validators)>{{validators...}};
}

}  // namespace codehub::utils