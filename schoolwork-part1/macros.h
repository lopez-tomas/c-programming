#ifndef MACROS_H
#define MACROS_H

#define ABS(x) (x) == 0 ? 0 : ((x) > 0 ? (x) : -(x))
#define INT_PART(x) (int)(x)

int toAbsoluteValue(int x);
int returnIntPart(float x);

#endif // MACROS_H
