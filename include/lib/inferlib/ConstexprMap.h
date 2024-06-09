#pragma once

#include <algorithm>
#include <array>
#include <utility>
#include <variant>

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

template <typename Key, typename Value, typename... Pairs>
constexpr auto MakeConstexprMap(Pairs&&... pairs) {
  static_assert((std::is_same_v<std::decay_t<decltype(pairs.first)>, Key> && ...),
                "All keys must be of the same type");
  static_assert((std::is_same_v<std::decay_t<decltype(pairs.second)>, Value> && ...),
                "All values must be of the same type");

  return ConstexprMap<Key, Value, sizeof...(pairs)>{
      std::array<std::pair<Key, Value>, sizeof...(pairs)>{std::forward<Pairs>(pairs)...}};
}

}  // namespace inferlib
