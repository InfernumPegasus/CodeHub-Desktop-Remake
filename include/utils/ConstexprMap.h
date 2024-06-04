#pragma once

#include <array>
#include <ranges>
#include <utility>

namespace inferlib {

template <typename Key, typename Value, std::size_t Size>
struct ConstexprMap {
  std::array<std::pair<Key, Value>, Size> data;

  [[nodiscard]] constexpr Value at(const Key& key) const {
    const auto itr =
        std::ranges::find_if(data, [&key](const auto& v) { return v.first == key; });
    if (itr != end(data)) {
      return itr->second;
    } else {
      throw std::range_error("Not Found");
    }
  }
};

template <typename Key, typename Variant>
struct ConstexprVariantMap
    : public ConstexprMap<Key, Variant, std::variant_size_v<Variant>> {};

}  // namespace inferlib
