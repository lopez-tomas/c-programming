#ifndef FUNCTIONS_H
#define FUNCTIONS_H

char* special_strcpy(char* dest, const char* orig);
void* mem_move(void* s1, const void* s2, size_t numberBytes);

int** createIntegerMatrix(unsigned numberFiles, unsigned numberColumns);
void fillIntegerMatrix(int** matrix, unsigned numberFiles, unsigned numberColumns);
void showIntegerMatrix(int** matrix, unsigned numberFiles, unsigned numberColumns);

#endif // FUNCTIONS_H
