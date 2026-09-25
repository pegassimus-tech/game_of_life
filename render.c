#include "render.h"

void init_render() {
    freopen("/dev/tty", "r", stdin);
    initscr();             // Инициализация ncurses
    noecho();              // Не выводить на экран то, что печатаем
    curs_set(0);           // Скрыть курсор
    cbreak();              // Режим мгновенного чтения клавиш
    nodelay(stdscr, TRUE); // ВАЖНО: getch() не будет ждать нажатия (игра идет сама)
}

void close_render() {
    endwin(); // Завершение работы ncurses
}

void draw_matrix(int** matrix, int a, int b, int speed) {
    clear();

    printw("Speed: %d ms | Press 'space' to Quit, 'a' to Speed Up, 'z' to Slow Down\n", speed / 1000);

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            if (matrix[i][j] == 1) {
                mvaddch(i + 1, j, '#');
            } else {
                mvaddch(i + 1, j, ' ');
            }
        }
    }
    refresh();
}
