#include <stdlib.h>
#include <stdio.h>

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

void free_matrix(int** ar) {
    if (ar == NULL) return;
    free(ar);
}

void swap_matrices(int ***matrix1, int ***matrix2) {
    int **temp = *matrix1;
    *matrix1 = *matrix2;
    *matrix2 = temp;
}

void input_matrix(int** matrix, int a, int b){
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

int check_zero_field(int** matrix, int a, int b){
    int sum = 0;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            sum += matrix[i][j];
        }
    }
    return sum;
}
