#ifndef MATRIX_H
#define MATRIX_H

#define ROWS 5
#define COLS 5

int showElementOfArray(int* mat, int numberRows, int numberColumns, int row, int col);
void mainDiagonal(int mat[ROWS][COLS], int numberRows, int numberColums);
void secondaryDiagonal(int mat[ROWS][COLS], int numberRows, int numberColums);
void upperTriangular(int mat[ROWS][COLS], int numberRows, int numberColums);
void lowerTriangular(int mat[ROWS][COLS], int numberRows, int numberColums);

#endif // MATRIX_H
