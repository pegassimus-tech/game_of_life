#ifndef UTILITIES_H
#define UTILITIES_H

int alloc_matrix(int*** ar, int a, int b);
void input_matrix(int** matrix, int a, int b);
void swap_matrices(int ***matrix1, int ***matrix2);
int check_zero_field(int** matrix, int a, int b);
void free_matrix(int** ar);


//// Изменение скорости (!!!!!!!)
int change_speed(char button, int *flag, int time);




#endif
