#pragma once

namespace inferlib {

/// Функция, проверяющая на равенство все элементы args
/// \tparam Args тип проверяемых аргументов
/// \param args проверяемые аргументы
/// \return истину, если все элементы равны, иначе ложь
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