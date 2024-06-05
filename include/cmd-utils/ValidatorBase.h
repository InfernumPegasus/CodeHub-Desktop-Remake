#pragma once

#include <memory>

#include "lib/inferlib/Printer.h"

namespace codehub::utils {

template <class Object, class Status>
class ValidatorBase {
 public:
  virtual ~ValidatorBase() = default;

  void SetNext(std::shared_ptr<ValidatorBase> next) { m_next = std::move(next); }

  virtual Status Validate(const Object&) = 0;

 protected:
  std::shared_ptr<ValidatorBase> m_next;
};

}  // namespace codehub::utils
