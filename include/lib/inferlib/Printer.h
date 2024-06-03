#pragma once

namespace inferlib {
/*
 Printer is a class that prints values in provided OStream.
 To use it, printed instances should have implemented operator<<.
 */
struct Printer {
  // TODO ввести класс PrinterTraits с характеристиками
  template <class OStream, class... T>
  static void Print(OStream& os, T&&... objs) {
    ((os << objs << ' '), ...);
  }

  template <class OStream, class... T>
  static void Println(OStream& os, T&&... objs) {
    Print(os, objs...);
    os << '\n';
  }
};
}  // namespace inferlib
