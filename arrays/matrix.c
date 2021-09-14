#include <stdio.h>
#include "matrix.h"

void mainDiagonal(int mat[ROWS][COLS], int numberRows, int numberColums) {
    int i;

    if (numberRows != numberColums) {
        printf("Your matrix is not square.\n");
        return;
    }

    for (i = 0; i < numberRows && i < numberColums; i++) {
        printf("mat[%d][%d] = %d\n", i, i, mat[i][i]);
    }
}

void secondaryDiagonal(int mat[ROWS][COLS], int numberRows, int numberColums) {
    int i, j;
    int nRows = numberRows - 1,
        nCols = numberColums - 1;

    if (numberRows != numberColums) {
        printf("Your matrix is not square.\n");
        return;
    }

    for (i = nRows, j = nCols; i >= 0 && j >= 0; i--, j--) {
        printf("mat[%d][%d] = %d\n", i, i, mat[i][i]);
    }
}
