#include "main.h"
#define ROWS 5
#define COLS 5

int main() {

    int mat[ROWS][COLS] = { {1,2,3}, {1,2,3}, {1,2,3} };
    int numberRows = 3,
        numberColums = 3;

    mainDiagonal(mat, numberRows, numberColums);
    printf("\n\n");
    secondaryDiagonal(mat, numberRows, numberColums);
    printf("\n\n");
    upperTriangular(mat, numberRows, numberColums);

    return 0;
}
