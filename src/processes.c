#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <ctype.h>
#include "../include/processes.h"

void print_processes_sorted() {
    DIR *dir;
    struct dirent *entry;

    // Открываем директорию /proc
    dir = opendir("/proc");
    if (dir == NULL) {
        perror("opendir");
        return;
    }

    // Читаем записи в директории
    while ((entry = readdir(dir)) != NULL) {
        // Проверяем, является ли запись PID-ом (начинается с цифры)
        if (entry->d_type == DT_DIR && isdigit(entry->d_name[0])) {
            printf("PID: %s\n", entry->d_name);  // Выводим PID
        }
    }

    // Закрываем директорию
    closedir(dir);
}
