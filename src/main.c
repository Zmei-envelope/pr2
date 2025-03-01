#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/users.h"
#include "../include/processes.h"
#include "../include/log.h"
#include "../include/errors.h"
#include "../include/help.h"

int main(int argc, char *argv[]) {
    int opt;
    char *log_path = NULL;  // Путь для перенаправления stdout
    char *errors_path = NULL;  // Путь для перенаправления stderr

    while ((opt = getopt(argc, argv, "uphl:e:")) != -1) {
        switch (opt) {
            case 'u':
                if (log_path) {
                    redirect_output_to_file(log_path);  // Перенаправляем stdout в файл
                }
                print_users_sorted();  // Выводим список пользователей
                break;
            case 'p':
                if (log_path) {
                    redirect_output_to_file(log_path);  // Перенаправляем stdout в файл
                }
                print_processes_sorted();  // Выводим список процессов
                break;
            case 'h':
                print_help();  // Выводим справку
                return 0;
            case 'l':
                log_path = optarg;  // Сохраняем путь для stdout
                break;
            case 'e':
                errors_path = optarg;  // Сохраняем путь для stderr
                redirect_errors_to_file(errors_path);  // Перенаправляем stderr в файл
                break;
            default:
                fprintf(stderr, "Unknown option: %c\n", opt);
                print_help();
                return 1;
        }
    }

    return 0;
}
