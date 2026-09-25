#ifndef GAME_FUNCTIONS_H
#define GAME_FUNCTIONS_H


// Проходка по матрице с изменениемями
void update_matrix(int** matrix1, int** matrix2, int a, int b);
// Подсчёт соседей клетки
int check_neighbours(int** matrix1, int i, int j, int a, int b);
// Жить или не жить...
int make_decision(int neighbors, int condition);




#endif
