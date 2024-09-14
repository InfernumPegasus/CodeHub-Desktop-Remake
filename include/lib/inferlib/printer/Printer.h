#pragma once

namespace inferlib {

/// Класс для вывода объектов в поток вывода
struct Printer {
  /// Метод для вывода объектов objs в поток вывода os.
  /// Необходима перегрузка оператора вывода для всех выводимых объектов.
  /// \tparam OStream тип потока вывода. Должен поддерживать оператор вывода
  /// \tparam T типы аргументов
  /// \param os объект потока вывода
  /// \param objs объекты для вывода
  /// \return поток вывода
  template <class OStream, class... T>
  static constexpr void Print(OStream& os, T&&... objs) {
    ((os << objs), ...);
  }

  /// Метод, аналогичный Print, однако добавляющий символ новой строки
  /// после вывода всех объектов
  /// \tparam OStream тип потока вывода. Должен поддерживать оператор вывода
  /// \tparam T типы аргументов
  /// \param os объект потока вывода
  /// \param objs объекты для вывода
  /// \return поток вывода
  template <class OStream, class... T>
  static constexpr void Println(OStream& os, T&&... objs) {
    Print(os, objs...);
    os << '\n';
  }
};
}  // namespace inferlib
