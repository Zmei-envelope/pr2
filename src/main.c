#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // Для getopt()
#include "../include/users.h"
#include "../include/processes.h"
#include "../include/log.h"
#include "../include/errors.h"
#include "../include/help.h"

int main(int argc, char *argv[]) {
    int opt;
    char *log_path = NULL;
    char *errors_path = NULL;

    while ((opt = getopt(argc, argv, "uphl:e:")) != -1) {
        switch (opt) {
            case 'u':
                if (log_path) {
                    redirect_output_to_file(log_path);
                }
                print_users_sorted();
                break;
            case 'p':
                if (log_path) {
                    redirect_output_to_file(log_path);
                }
                print_processes_sorted();
                break;
            case 'h':
                print_help();
                return 0;
            case 'l':
                log_path = optarg;
                break;
            case 'e':
                errors_path = optarg;
                redirect_errors_to_file(errors_path);
                break;
            default:
                fprintf(stderr, "Unknown option: %c\n", opt);
                print_help();
                return 1;
        }
    }

    return 0;
}
