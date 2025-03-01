#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/errors.h"

void redirect_errors_to_file(const char *path) {
    // Проверяем доступ к файлу
    if (access(path, W_OK) == -1) {
        // Если файл недоступен, создаем его
        FILE *file = fopen(path, "w");
        if (file == NULL) {
            perror("fopen");
            exit(EXIT_FAILURE);
        }
        fclose(file);
    }

    // Перенаправляем stderr в файл
    FILE *file = freopen(path, "a", stderr);
    if (file == NULL) {
        perror("freopen");
        exit(EXIT_FAILURE);
    }
}
