#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>  // Для opendir(), readdir()
#include <ctype.h>  // Для isdigit()
#include "../include/processes.h"

void print_processes_sorted() {
    DIR *dir;
    struct dirent *entry;

    dir = opendir("/proc");
    if (dir == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR && isdigit(entry->d_name[0])) {
            printf("PID: %s\n", entry->d_name);
        }
    }

    closedir(dir);
}
