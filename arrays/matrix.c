#include <stdio.h>
#include "matrix.h"

int showElementOfArray(int* mat, int numberRows, int numberColumns, int row, int col) {
    return *(mat + (row * numberColumns) + col);
}

void mainDiagonal(int mat[ROWS][COLS], int numberRows, int numberColums) {
    int i;

    if (numberRows != numberColums) {
        printf("Your matrix is not square.\n");
        return;
    }

    for (i = 0; i < numberRows; i++) {
        printf("mat[%d][%d] = %d\n", i, i, mat[i][i]);
    }
}

void secondaryDiagonal(int mat[ROWS][COLS], int numberRows, int numberColums) {
    int i;
    int nCols = numberColums - 1;

    if (numberRows != numberColums) {
        printf("Your matrix is not square.\n");
        return;
    }

    for (i = nCols; i >= 0; i--) {
        printf("mat[%d][%d] = %d\n", i, i, mat[i][i]);
    }
}

void upperTriangular(int mat[ROWS][COLS], int numberRows, int numberColums) {
    int i, j;

    for(i = 0; i < numberRows - 1; i++) {
        for(j = 0; j < numberColums - 1 - i; j++) {
            printf("%d\t", i, j, mat[i][j]);
        }
        printf("\n");
    }
}
