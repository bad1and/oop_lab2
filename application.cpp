#include "application.h"
#include <ncurses.h>
#include <locale.h>

int position = 0;
int n_button;

void Application::showMenu() const {
    clear();
    printw("Работа с массивом (ПР2, комплексные числа)\n");
    printw("-------------------------------------------\n\n");

    const char* screen[9] = {
        "1. Ввод массива",
        "2. Вывод массива",
        "3. Изменить размерность",
        "4. Изменить элемент",
        "5. Среднее и СКО",
        "6. Сортировка по возрастанию",
        "7. Сортировка по убыванию",
        "8. Выход",
        ""
    };

    for (int i = 0; i < 8; i++) {
        if (i == position) {
            printw("%s  <---\n", screen[i]);
        } else {
            printw("%s\n", screen[i]);
        }
    }
    refresh();
}

void Application::run() {
    setlocale(LC_ALL, "");
    initscr();

    noecho();
    keypad(stdscr, TRUE);

    while (true) {
        showMenu();
        n_button = getch();

        if (n_button == KEY_UP) {
            position = (position - 1 + 8) % 8;
        } else if (n_button == KEY_DOWN) {
            position = (position + 1) % 8;
        }

        if (n_button == 10) { // Enter
            clear();
            switch (position) {
                case 0: // ввод массива
                    echo();
                    arr.input();
                    noecho();
                    getch();
                    break;

                case 1: // вывод массива
                    if (arr.isEmpty()) {
                        printw("Ошибка: массив пуст!\n");
                    } else {
                        arr.output();
                    }
                    getch();
                    break;

                case 2: { // изменить размерность
                    echo();
                    int n;
                    printw("Новая размерность: ");
                    if (scanw("%d", &n) != 1 || n <= 0) {
                        printw("Ошибка: размер должен быть положительным!\n");
                    } else {
                        arr.resize(n);
                        printw("Размер изменён!\n");
                    }
                    noecho();
                    getch();
                    break;
                }

                case 3: { // изменить элемент
                    if (arr.isEmpty()) {
                        printw("Ошибка: массив пуст!\n");
                        getch();
                        break;
                    }
                    echo();
                    int i; double re, im;
                    printw("Введите индекс и новое значение (Re Im): ");
                    if (scanw("%d %lf %lf", &i, &re, &im) != 3) {
                        printw("Ошибка ввода!\n");
                    } else if (i < 0 || i >= arr.getSize()) {
                        printw("Ошибка: индекс вне диапазона!\n");
                    } else {
                        arr.setElement(i, number(re, im));
                        printw("Элемент изменён!\n");
                    }
                    noecho();
                    getch();
                    break;
                }

                case 4: // среднее и СКО
                    if (arr.isEmpty()) {
                        printw("Ошибка: массив пуст!\n");
                    } else {
                        printw("Среднее = "); arr.average().print();
                        printw("\nСКО = "); arr.deviation().print();
                        printw("\n");
                    }
                    getch();
                    break;

                case 5: // сортировка по возрастанию
                    if (arr.isEmpty()) {
                        printw("Ошибка: массив пуст!\n");
                    } else {
                        arr.sortAsc();
                        printw("Сортировка по возрастанию выполнена!\n");
                    }
                    getch();
                    break;

                case 6: // сортировка по убыванию
                    if (arr.isEmpty()) {
                        printw("Ошибка: массив пуст!\n");
                    } else {
                        arr.sortDesc();
                        printw("Сортировка по убыванию выполнена!\n");
                    }
                    getch();
                    break;

                case 7: // выход
                    endwin();
                    return;
            }
        }
    }
}
