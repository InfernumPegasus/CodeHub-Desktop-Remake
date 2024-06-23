#pragma once

#include <memory>

#include "lib/inferlib/Printer.h"

namespace codehub::utils {

template <class Object, class Status>
class IValidator {
 public:
  virtual ~IValidator() = default;

  constexpr void SetNext(std::unique_ptr<IValidator> next) { m_next = std::move(next); }

  constexpr virtual Status IsValid(const Object&) = 0;

 protected:
  std::unique_ptr<IValidator> m_next;
};

}  // namespace codehub::utils
