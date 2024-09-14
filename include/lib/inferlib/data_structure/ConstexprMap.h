#pragma once

#include <algorithm>
#include <array>
#include <utility>
#include <variant>

namespace inferlib {

/// Хэш-таблица времени компиляции. Использует память стека
/// \tparam Key тип ключа
/// \tparam Value тип значения
/// \tparam Size количество пар ключ-значение
template <typename Key, typename Value, std::size_t Size>
struct ConstexprMap {
  std::array<std::pair<Key, Value>, Size> data;

  /// Метод поиска значения по ключу
  /// \param key ключ, по которому производится поиск
  /// \return соответствующе ключу значение. Если не найдено, выкидывает range_error
  [[nodiscard]] constexpr Value At(const Key& key) const {
    const auto itr = std::find_if(data.cbegin(), data.cend(),
                                  [&key](const auto& v) { return v.first == key; });
    if (itr != end(data)) {
      return itr->second;
    } else {
      throw std::range_error("Not Found");
    }
  }

  /// Метод проверки на соответствующее ключу значение
  /// \param key ключ, по которому производится поиск
  /// \return истину, если значение найдено, иначе ложь
  [[nodiscard]] constexpr bool Contains(const Key& key) const {
    const auto itr = std::find_if(data.cbegin(), data.cend(),
                                  [&key](const auto& v) { return v.first == key; });
    return itr != end(data);
  }
};

/// Функция, формирующая объект ConstexprMap из переданных пар ключ-значение
/// \tparam Key тип ключа
/// \tparam Value тип значения
/// \tparam Pairs тип аргументов-пар
/// \param pairs аргументы, из которых формируется ConstexprMap
/// \return ConstexprMap с типом ключа Key и типом значения Value
template <typename Key, typename Value, typename... Pairs>
constexpr auto MakeConstexprMap(Pairs&&... pairs) {
  return ConstexprMap<Key, Value, sizeof...(pairs)>{
      std::array<std::pair<Key, Value>, sizeof...(pairs)>{std::forward<Pairs>(pairs)...}};
}

/// Вспомогательная функция для функции ExtractKeys
/// \tparam Key тип ключа
/// \tparam Value тип значения
/// \tparam Size количество ключей
/// \tparam I индексы последовательностей
/// \param map объект ConstexprMap, из которого требуется извлечь ключи
/// \return std::array типа Key размером Size
template <typename Key, typename Value, std::size_t Size, std::size_t... I>
constexpr auto ExtractKeysImpl(const ConstexprMap<Key, Value, Size>& map,
                               std::index_sequence<I...>) {
  return std::array<Key, Size>{map.data[I].first...};
}

/// Функция, извлекающая все ключи из объекта ConstexprMap
/// \tparam Key тип ключа
/// \tparam Value тип значения
/// \tparam Size количество ключей
/// \param map объект ConstexprMap, из которого требуется извлечь ключи
/// \return std::array типа Key размером Size
template <typename Key, typename Value, std::size_t Size>
constexpr auto ExtractKeys(const ConstexprMap<Key, Value, Size>& map) {
  return ExtractKeysImpl(map, std::make_index_sequence<Size>{});
}

}  // namespace inferlib
