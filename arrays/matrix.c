#include <stdio.h>
#include "matrix.h"

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
    int nRows = numberRows - 1;

    if (numberRows != numberColums) {
        printf("Your matrix is not square.\n");
        return;
    }

    for (i = nRows; i >= 0; i--) {
        printf("mat[%d][%d] = %d\n", i, i, mat[i][i]);
    }
}
