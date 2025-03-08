#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <libgen.h>  // Для dirname()
#include <sys/stat.h>  // Для mkdir()
#include <string.h>  // Для strdup()
#include "../include/log.h"

// Статическая функция для создания директории, если она не существует
static void create_directory_if_not_exists(const char *path) {
    char *path_copy = strdup(path);
    char *dir = dirname(path_copy);

    if (access(dir, F_OK) == -1) {
        if (mkdir(dir, 0755) == -1) {
            perror("mkdir");
            free(path_copy);
            exit(EXIT_FAILURE);
        }
    }

    free(path_copy);
}

// Функция для перенаправления stdout в файл
void redirect_output_to_file(const char *path) {
    if (path == NULL) {
        fprintf(stderr, "Error: No path provided for log file.\n");
        exit(EXIT_FAILURE);
    }

    create_directory_if_not_exists(path);
    FILE *file = freopen(path, "a", stdout);
    if (file == NULL) {
        perror("freopen");
        exit(EXIT_FAILURE);
    }
}
