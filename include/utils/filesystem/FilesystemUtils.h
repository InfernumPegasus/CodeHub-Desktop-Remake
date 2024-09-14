#pragma once

#include <filesystem>
#include <vector>

namespace codehub::filesystem {

/// Проверка наличия элемента файловой системы
/// \param path путь к проверяемому элементу
/// \return истину, если элемент существует, иначе ложь
[[nodiscard]] bool ElementExists(const std::filesystem::path& path);

/// Определяет путь домашнего каталога
/// \return полный путь домашнего каталога
[[nodiscard]] std::filesystem::path GetHomePath();

/// Функция для прочтения текстового файла
/// \param path путь к файлу
/// \return std::vector с прочитанными строками из файла
[[nodiscard]] std::vector<std::string> ReadTextFile(const std::filesystem::path& path);

/// Функция для создания файла
/// \param path путь для создаваемого файла
/// \return истину в случае успеха, иначе ложь
bool CreateFile(const std::filesystem::path& path);

/// Функция для создания папки
/// \param path путь для создаваемой папки
/// \return истину в случае успеха, иначе ложь
bool CreateDirectory(const std::filesystem::path& path);

}  // namespace codehub::filesystem