#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stddef.h>

typedef struct {
	unsigned dni; // documento nacional de indentidad = national identity document
	char completeName[100];
	float grade;
} t_Students;

void *mem_move(void *dest, const void *orig, size_t n);
void swap(void *s1, void *s2, size_t n);

void showInteger(void* vec);
void showFloat(void* vec);

void showVector(void* buffer, size_t element, size_t numberElements, void act(void*));

#endif // FUNCTIONS_H
