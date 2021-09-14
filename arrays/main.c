#include "main.h"
#define ROWS 5
#define COLS 5

int main() {

    int mat[ROWS][COLS] = { {1,2,3,4,5}, {1,2,3,4,5}, {1,2,3,4,5}, {1,2,3,4,5}, {1,2,3,4,5} };
    int numberRows = 5,
        numberColums = 5;

    mainDiagonal(mat, numberRows, numberColums);
    printf("\n\n");
    secondaryDiagonal(mat, numberRows, numberColums);

    return 0;
}
