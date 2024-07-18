cmake_minimum_required(VERSION 3.22.1)
project(CodeHub)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall -Wpedantic -Wno-maybe-uninitialized -Werror -O3")

file(GLOB PARSER_SOURCES
        "src/utils/parser/CommandLineParser.cpp"
        "src/utils/parser/ParsedCommand.cpp"
        "src/utils/parser/IniConfigParser.cpp"
        "src/utils/parser/ParsedIniFile.cpp"
)
file(GLOB COMMAND_SOURCES "src/command/*.cpp")
file(GLOB COMMAND_UTILS_SOURCES "src/command/utils/CommandExecutor.cpp")
file(GLOB FILESYSTEM_UTILS_SOURCES "src/utils/filesystem/FilesystemUtils.cpp")

add_library(global
        ${PARSER_SOURCES}
        ${COMMAND_SOURCES}
        ${COMMAND_UTILS_SOURCES}
        ${FILESYSTEM_UTILS_SOURCES}
)

target_include_directories(global PUBLIC include)
target_include_directories(global PRIVATE src)

add_executable(
        ${PROJECT_NAME}
        src/vcs/VCSApplication.cpp
        main.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE
        global
)
