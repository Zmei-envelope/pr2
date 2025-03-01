cmake_minimum_required(VERSION 3.10)
project(pr2)

set(CMAKE_C_STANDARD 99)

# Указываем, где искать заголовочные файлы
include_directories(include)

# Список исходных файлов
set(SOURCES
    src/main.c
    src/users.c
    src/processes.c
    src/log.c
    src/errors.c
    src/help.c
)

# Создаем исполняемый файл
add_executable(pr2 ${SOURCES})
