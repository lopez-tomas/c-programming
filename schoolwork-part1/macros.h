#ifndef MACROS_H
#define MACROS_H

#define ABS(x) (x) == 0 ? 0 : ((x) > 0 ? (x) : -(x))
#define INT_PART(x) (int)(x)
#define DECIMAL_PART(x) (x) - INT_PART(x)
#define IS_NUMBER(c) (INT_PART(c) >= 48 && INT_PART(c) <= 57) ? 1 : 0
#define IS_MAYUS(c) (INT_PART(c) >= 65 && INT_PART(c) <= 90) ? 1 : 0
#define IS_MINUS(c) (INT_PART(c) >= 97 && INT_PART(c) <= 122) ? 1 : 0
#define IS_LETTER(c) (IS_MAYUS(c) || IS_MINUS(c)) ? 1 : 0
#define IS_WHITE(c) (c) == ' ' ? 1 : 0

int toAbsoluteValue(int x);
int returnIntPart(float x);
float returnDecimalPart(float x);

#endif // MACROS_H
