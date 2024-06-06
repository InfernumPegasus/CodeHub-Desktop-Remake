#pragma once

#include <algorithm>
#include <array>
#include <utility>

namespace inferlib {

template <typename Key, typename Value, std::size_t Size>
struct ConstexprMap {
  std::array<std::pair<Key, Value>, Size> data;

  [[nodiscard]] constexpr Value At(const Key& key) const {
    const auto itr = std::find_if(data.cbegin(), data.cend(),
                                  [&key](const auto& v) { return v.first == key; });
    if (itr != end(data)) {
      return itr->second;
    } else {
      throw std::range_error("Not Found");
    }
  }

  [[nodiscard]] constexpr bool Contains(const Key& key) const {
    const auto itr = std::find_if(data.cbegin(), data.cend(),
                                  [&key](const auto& v) { return v.first == key; });
    return itr != end(data);
  }
};

template <typename Key, typename Variant>
struct ConstexprVariantMap
    : public ConstexprMap<Key, Variant, std::variant_size_v<Variant>> {};

}  // namespace inferlib
