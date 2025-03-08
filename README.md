
```markdown
# Console Utility

Это консольная утилита на языке C, которая обрабатывает аргументы командной строки и выполняет следующие действия:

- Выводит список пользователей и их домашних директорий.
- Выводит список запущенных процессов.
- Перенаправляет вывод и ошибки в указанные файлы.

## Сборка

Для сборки программы используйте CMake:

1. Создайте директорию `build` и перейдите в неё:
   ```bash
   mkdir build
   cd build
   ```

2. Соберите проект:
   ```bash
   cmake ..
   make
   ```

## Использование

Программа поддерживает следующие аргументы командной строки:

- `-u`, `--users`: Выводит список пользователей и их домашних директорий.
- `-p`, `--processes`: Выводит список запущенных процессов.
- `-h`, `--help`: Выводит справку по использованию программы.
- `-l PATH`, `--log PATH`: Перенаправляет стандартный вывод (stdout) в указанный файл.
- `-e PATH`, `--errors PATH`: Перенаправляет стандартный вывод ошибок (stderr) в указанный файл.

### Примеры

1. Вывод списка пользователей:
   ```bash
   ./my_utility -u
   ```

2. Вывод списка процессов:
   ```bash
   ./my_utility -p
   ```

3. Вывод списка пользователей в файл:
   ```bash
   ./my_utility -u -l /path/to/output.log
   ```

4. Вывод ошибок в файл:
   ```bash
   ./my_utility -u -e /path/to/errors.log
   ```

5. Вывод справки:
   ```bash
   ./my_utility -h
   ```

## Лицензия

Этот проект распространяется под лицензией MIT. Подробности см. в файле [LICENSE](LICENSE).
```

---

### Как добавить `README.md` в проект

1. Создайте файл `README.md` в корневой директории вашего проекта:
   ```bash
   touch README.md
   ```

2. Откройте файл `README.md` в текстовом редакторе и вставьте содержимое, приведенное выше.

3. Добавьте `README.md` в Git:
   ```bash
   git add README.md
   git commit -m "Added README.md"
   git push origin main  # или master
   ```

---

