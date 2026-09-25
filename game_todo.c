#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>


void swap_matrices(int ***matrix1, int ***matrix2); //sherriay
void input_matrix(int** matrix, int a, int b); // sherriay
int check_zero_field(int** matrix, int a, int b); // sherriay


void update_matrix(int** matrix1, int** matrix2, int a, int b); //sherriay
int check_neighbours(int** matrix, int i, int j, int a, int b); //sherriay
int make_decision(int neighbours, int condition); // sherriay



void init_render(); //armandab
void draw_matrix(int** matrix, int a, int b, int speed); //armandab
int alloc_matrix(int*** ar, int a, int b); //armandab


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
        if ((ch == 'a' || ch == 'A') && speed > 100000) speed -= 10000;
        if ((ch == 'z' || ch == 'Z') && speed < 100000000) speed += 10000;

        draw_matrix(matrix, rows, cols, speed);

        update_matrix(matrix, next_matrix, rows, cols);
        swap_matrices(&matrix, &next_matrix);

        // если все умерли :(
        if (check_zero_field(matrix, rows, cols) == 0) status = 0;

        usleep(speed);
    }


    endwin(); 
    if (matrix != NULL) free(matrix);
    if (matrix != NULL) free(next_matrix);

    return 0;
}

int alloc_matrix(int*** ar, int a, int b) {
    int status = 1;
    *ar = NULL;
    *ar = malloc(a * b * sizeof(int) + a * sizeof(int*));
    if (*ar == NULL) status = 0;
    if (status){
        int* ptr = (int*)(*ar + a);
        for (int i = 0; i < a; i++) (*ar)[i] = ptr + b * i;
    }
    return status;
}




void swap_matrices(int ***matrix1, int ***matrix2) {
    
}

void input_matrix(int** matrix, int a, int b){
    
}

int check_zero_field(int** matrix, int a, int b){
    
}


// проходка по матрице с изменениемями
void update_matrix(int** matrix1, int** matrix2, int a, int b){
    
}

// подсчёт соседей
int check_neighbours(int** matrix, int i, int j, int a, int b){
    
}

int make_decision(int neighbours, int condition) {

}


void init_render() {
    freopen("/dev/tty", "r", stdin);
    initscr();             
    noecho();              
    curs_set(0);           
    cbreak();             
    nodelay(stdscr, TRUE); 
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
