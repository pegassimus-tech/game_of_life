#include "game_functions.h"

// проходка по матрице с изменениемями
void update_matrix(int** matrix1, int** matrix2, int a, int b){
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            matrix2[i][j] = make_decision(check_neighbours(matrix1, i, j, a, b), matrix1[i][j]);
        }
    }
}

// подсчёт соседей
int check_neighbours(int** matrix, int i, int j, int a, int b){
    int sum = 0;
    // координаты соседей
    int i_minus = i - 1, j_minus = j - 1, i_plus = i + 1, j_plus = j + 1;

    // i и j для координат соседей, которые выходят за рамки поля
    if (i_minus < 0) i_minus = a - 1;
    if (j_minus < 0) j_minus = b - 1;
    if (i_plus > a - 1) i_plus = 0;
    if (j_plus > b - 1) j_plus = 0;

    // Обходим по часовой стрелке, начиная с "северо-запада"
    sum += matrix[i_minus][j_minus];
    sum += matrix[i_minus][j];
    sum += matrix[i_minus][j_plus];
    sum += matrix[i][j_plus];
    sum += matrix[i_plus][j_plus];
    sum += matrix[i_plus][j];
    sum += matrix[i_plus][j_minus];
    sum += matrix[i][j_minus];

    return sum;
}

int make_decision(int neighbours, int condition) {
    int result = -1;
    if ((neighbours == 2 || neighbours == 3) && condition == 1) {
        result = 1;
    } else if (neighbours == 3 && condition == 0) {
        result = 1;
    } else {
        result = 0;
    }
    return result;
}
