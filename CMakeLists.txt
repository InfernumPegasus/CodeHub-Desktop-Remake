cmake_minimum_required(VERSION 3.22.1)
project(CodeHub)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (CMAKE_CXX_COMPILER_ID MATCHES GNU)
    add_compile_options(-W)
    add_compile_options(-Wall)
    add_compile_options(-Wextra)
    add_compile_options(-Wpedantic)
#    add_compile_options(-Werror)

    if (CMAKE_BUILD_TYPE STREQUAL "Debug")
        add_compile_options(-O0)
        add_compile_options(-g3)
        add_compile_options(-fsanitize=address)
        add_link_options(-fsanitize=address)
        add_compile_options(-fsanitize=undefined)
        add_link_options(-fsanitize=undefined)
    endif ()

    if (CMAKE_BUILD_TYPE STREQUAL "Release")
        add_compile_options(-O2)
        add_compile_options(-g3)
    endif ()
endif ()

if (CMAKE_CXX_COMPILER_ID MATCHES MSVC)
    add_compile_options(/W3)
    if (CMAKE_BUILD_TYPE STREQUAL "Release")
        add_compile_options(/0t)
    else ()
        add_compile_options(/Zi)
    endif ()
endif ()

include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB PARSER_SOURCES
        "src/utils/parser/CommandLineParser.cpp"
        "src/utils/parser/IniConfigParser.cpp"
        "src/utils/parser/ParsedIniFile.cpp"
)
file(GLOB CONFIG_SOURCES "src/utils/config/*.cpp")
file(GLOB COMMAND_SOURCES "src/command/*.cpp")
file(GLOB FILESYSTEM_UTILS_SOURCES "src/utils/filesystem/FilesystemUtils.cpp")
file(GLOB VCS_APPLICATION_SOURCES "src/vcs/VCSApplication.cpp")

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
        ${VCS_APPLICATION_SOURCES}
        main.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE
        parser command config filesystem_utils
)
