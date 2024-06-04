cmake_minimum_required(VERSION 3.22.1)
project(CodeHub)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall -pedantic -Wno-maybe-uninitialized -Werror -O3")

add_library(global
        src/cmd-utils/ParsedCommand.cpp
        src/cmd-utils/CommandLineParser.cpp
        src/cmd-utils/CommandExecutor.cpp
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