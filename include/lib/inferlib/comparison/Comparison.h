#pragma once

namespace inferlib {

template <class... Args>
constexpr bool AllEqual(const Args&... args) {
  if constexpr (sizeof...(args) == 0) {
    return true;
  } else {
    return [](const auto& first, const auto&... rest) {
      return ((first == rest) && ...);
    }(args...);
  }
}

}  // namespace inferlib