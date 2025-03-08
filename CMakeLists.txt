cmake_minimum_required(VERSION 3.10)
project(Console_C_utility_1 C)

set(CMAKE_C_STANDARD 99)

include_directories(include)

set(SOURCES
    src/main.c
    src/log.c
    src/errors.c
    src/users.c
    src/processes.c
    src/help.c
)

add_executable(my_utility ${SOURCES})
