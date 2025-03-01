#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pwd.h>
#include "../include/users.h"

void print_users_sorted() {
    struct passwd *pw;

    // Открываем базу данных пользователей
    setpwent();

    // Читаем записи о пользователях
    while ((pw = getpwent()) != NULL) {
        printf("%s: %s\n", pw->pw_name, pw->pw_dir);  // Выводим имя пользователя и домашнюю директорию
    }

    // Закрываем базу данных
    endpwent();
}
