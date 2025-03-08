#ifndef ERRORS_H
#define ERRORS_H

#include <stdio.h>

// Функция для перенаправления stderr в файл
void redirect_errors_to_file(const char *path);

#endif
