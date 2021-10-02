#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stddef.h>

typedef struct {
	unsigned dni; // documento nacional de indentidad = national identity document
	char completeName[100];
	float grade;
} t_Students;

void *mem_cpy(void *dest, const void *orig, size_t n);
void swap(void *s1, void *s2, size_t sizeElement);

void showInteger(void* vec);
void showFloat(void* vec);
void showStudent(void* vec);

void showVector(void* buffer, size_t element, size_t numberElements, void act(void*));

int descendentIntegers(const void* intA, const void* intB);
int ascendentIntegers(const void* intA, const void* intB);

void* findMinor(const void* base, size_t numberElements, size_t sizeElement, int compare(const void*, const void*));
void sortSelection(void* base, size_t numberElements, size_t sizeElement, int compare(const void*, const void*));

#endif // FUNCTIONS_H
