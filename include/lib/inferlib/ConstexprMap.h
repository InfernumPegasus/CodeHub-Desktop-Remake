#pragma once

#include <algorithm>
#include <array>
#include <expected>
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

template <typename Key, typename Value, typename... Pairs>
constexpr auto MakeConstexprMap(Pairs&&... pairs) {
  return ConstexprMap<Key, Value, sizeof...(pairs)>{
      std::array<std::pair<Key, Value>, sizeof...(pairs)>{std::forward<Pairs>(pairs)...}};
}

template <typename Key, typename Value, std::size_t Size, std::size_t... I>
constexpr auto ExtractKeysImpl(const ConstexprMap<Key, Value, Size>& map,
                               std::index_sequence<I...>) {
  return std::array<Key, Size>{map.data[I].first...};
}

template <typename Key, typename Value, std::size_t Size>
constexpr auto ExtractKeys(const ConstexprMap<Key, Value, Size>& map) {
  return ExtractKeysImpl(map, std::make_index_sequence<Size>{});
}

}  // namespace inferlib
