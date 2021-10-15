#ifndef EXERCISES_H
#define EXERCISES_H

#include "./dynamic/Stack.h"
//#include "./static/Stack.h"

int isMathExpressionCorrect(const char* mathExpression);
int stacking(const char* number, t_Stack* stack);
void addTwoNumbers(const char* numberA, const char* numberB, t_Stack* result);

#endif // EXERCISES_H
