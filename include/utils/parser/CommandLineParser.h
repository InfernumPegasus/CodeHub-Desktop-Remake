#pragma once

#include "ParsedCommand.h"
#include "ParserUtils.h"
#include "utils/status/Status.h"

namespace codehub::utils {

/*
 * Парсер командной строки. Включает в себя определение ключевого слова (keyword),
 * флагов (с параметрами или без), а также простыми аргументами.
 * Например, при аргументах: config --arged=123 --noarged ./ just_a_param --evo_flag
 * ключевое слово (keyword) - config,
 * флаги с параметрами      - --arged=123
 * флаги без параметров     - --noarged, --evo_flag
 * простые аргументы        - ./, just_a_param
 */
struct CommandLineParser {

  /// Метод для парсинга командной строки в готовый к использованию объект
  /// \param argc количество аргументов командной строки
  /// \param argv массив аргументов командной строки
  /// \return объект команды
  [[nodiscard]] static ParsedCommand Parse(int argc, char* argv[]);

 private:

  /// Метод для создания списка невладеющих строк из аргументов командной строки
  /// \param argc количество аргументов командной строки
  /// \param argv массив аргументов командной строки
  /// \return массив аргументов [*argv + 1; *argv + argc - 1], если argc >= 2,
  /// иначе пустой массив
  [[nodiscard]] static constexpr ArgsListView ArgvToStringViews(int argc, char* argv[]);

  /// Метод для извлечения флагов и их параметров (при их наличии)
  /// \param rawArgs массив аргументов командной строки
  /// \return массив флагов и их значений (при их наличии)
  [[nodiscard]] static constexpr FlagsListView ExtractFlagsWithArgs(
      const ArgsListView& rawArgs);

  /// Метод для извлечения простых аргументов
  /// \param rawArgs массив аргументов командной строки
  /// \return массив простых аргументов
  [[nodiscard]] static constexpr ArgsListView ExtractSimpleArgs(
      const ArgsListView& rawArgs);
};

}  // namespace codehub::utils
