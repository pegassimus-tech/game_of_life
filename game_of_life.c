#include "utilities.h"
#include "game_functions.h"
#include "render.h"
#include <unistd.h> // Для usleep()

int main() {
    int rows = 25, cols = 80;
    int **matrix, **next_matrix;
    int speed = 100000;


    alloc_matrix(&matrix, rows, cols);
    alloc_matrix(&next_matrix, rows, cols);

    input_matrix(matrix, rows, cols);

    init_render();

    int status = 1;
    while (status) {
        int ch = getch();
        if (ch == ' ') status = 0;
        if ((ch == 'a' || ch == 'A') && speed > 10000) speed -= 10000;
        if ((ch == 'z' || ch == 'Z') && speed < 1000000) speed += 10000;

        draw_matrix(matrix, rows, cols, speed);

        update_matrix(matrix, next_matrix, rows, cols);
        swap_matrices(&matrix, &next_matrix);

        // если все умерли :(
        if (check_zero_field(matrix, rows, cols) == 0) status = 0;

        usleep(speed);
    }


    close_render();
    free_matrix(matrix); // Твой free_matrix теперь должен просто делать free
    free_matrix(next_matrix);

    return 0;
}
