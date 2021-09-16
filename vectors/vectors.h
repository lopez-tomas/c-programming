#ifndef VECTORS_H
#define VECTORS_H

void printArray(int* vec, int posAct, int tam);
int fillArray(int* vec, int posAct, int tam);
int insertElementInto(int* vec, int element, int pos, int* posAct, int tam);
void insertElementIntoOrderedVector(int* vec, int element, int* posAct, int tam);
void eliminateElement(int* vec, int element, int* posAct, int tam);
int disjointVectors(int* vec1, const int numberElementsVec1, int* vec2, const int numberElementsVec2);
int symmetricVector(int* vec, const int numElements);

#endif // VECTORS_H
