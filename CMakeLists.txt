cmake_minimum_required(VERSION 3.22.1)
project(CodeHub)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall -Wpedantic -Wno-maybe-uninitialized -Werror -O3")

file(GLOB PARSER_SOURCES
        "src/utils/parser/ParsedCommand.cpp"
        "src/utils/parser/CommandLineParser.cpp"
)
file(GLOB COMMAND_SOURCES "src/command/*.cpp")
file(GLOB COMMAND_UTILS_SOURCES "src/command/utils/CommandExecutor.cpp")
file(GLOB FILESYSTEM_UTILS_SOURCES "src/lib/filesystem/FilesystemUtils.cpp")

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
        main.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE
        global
)
