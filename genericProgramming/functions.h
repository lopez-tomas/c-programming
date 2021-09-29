#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stddef.h>

typedef struct {
	unsigned dni;
	char apyn[100];
} tAlumnos;

void *mem_move(void *dest, const void *orig, size_t n);
void swap(void *s1, void *s2, size_t n);

#endif // FUNCTIONS_H
