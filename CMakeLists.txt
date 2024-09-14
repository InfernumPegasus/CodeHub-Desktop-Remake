cmake_minimum_required(VERSION 3.22.1)
project(CodeHub)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic -Wno-maybe-uninitialized -O3")

include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB PARSER_SOURCES
        "src/utils/parser/CommandLineParser.cpp"
        "src/utils/parser/IniConfigParser.cpp"
        "src/utils/parser/ParsedIniFile.cpp"
)
file(GLOB CONFIG_SOURCES "src/utils/config/*.cpp")
file(GLOB COMMAND_SOURCES "src/command/*.cpp")
file(GLOB FILESYSTEM_UTILS_SOURCES "src/utils/filesystem/FilesystemUtils.cpp")

add_library(parser ${PARSER_SOURCES})
add_library(command ${COMMAND_SOURCES})
add_library(config ${CONFIG_SOURCES})
add_library(filesystem_utils ${FILESYSTEM_UTILS_SOURCES})

target_include_directories(parser PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_include_directories(command PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_include_directories(config PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_include_directories(filesystem_utils PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_executable(
        ${PROJECT_NAME}
        src/vcs/VCSApplication.cpp
        main.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE
        parser command config filesystem_utils
)
