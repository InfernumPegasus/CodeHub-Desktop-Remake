#pragma once

#include <memory>

#include "lib/inferlib/Printer.h"

namespace codehub::utils {

template <class T>
class ValidatorBase {
 public:
  virtual ~ValidatorBase() = default;

  void SetNext(std::shared_ptr<ValidatorBase> next) { m_next = std::move(next); }

  virtual bool Validate(const T&) = 0;

 protected:
  std::shared_ptr<ValidatorBase> m_next;
};

}  // namespace codehub::utils
