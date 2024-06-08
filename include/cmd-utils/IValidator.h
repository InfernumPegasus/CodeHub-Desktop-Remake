#pragma once

#include <memory>

#include "lib/inferlib/Printer.h"

namespace codehub::utils {

template <class Object, class Status>
class IValidator {
 public:
  virtual ~IValidator() = default;

  constexpr void SetNext(std::shared_ptr<IValidator> next) { m_next = next; }

  constexpr virtual Status IsValid(const Object&) = 0;

 protected:
  std::shared_ptr<IValidator> m_next;
};

}  // namespace codehub::utils
