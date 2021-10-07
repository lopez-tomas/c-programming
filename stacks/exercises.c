#include <string.h>
#include "exercises.h"
#include "../schoolwork-part1/macros.h"

#define isOpeningParenthesis(c) ( (c) == '(' )
#define isClosingParenthesis(c) ( (c) == ')' )

#define isOpeningBracket(c) ( (c) == '[' )
#define isClosingBracket(c) ( (c) == ']' )

#define isOpeningBrace(c) ( (c) == '{' )
#define isClosingBrace(c) ( (c) == '}' )

#define isOpenness(c) ( isOpeningParenthesis(c) || isOpeningBracket(c) || isOpeningBrace(c) )
#define isClosure(c) ( isClosingParenthesis(c) || isClosingBracket(c) || isClosingBrace(c) )

int isMathExpressionCorrect(const char* mathExpression) {
    t_Stack stack;
    char obj;

    createStack(&stack);

    while(*mathExpression) {
        if ( isOpenness(*mathExpression) ) {
            push(&stack, mathExpression, sizeof(char));
        }

        if ( isClosure(*mathExpression) ) {
            if (isEmpty(&stack)) {
                return 0;
            }

            pop(&stack, &obj, sizeof(char));
            if ( isClosingParenthesis(*mathExpression) && !isOpeningParenthesis(obj) ) { return 0; }
            if ( isClosingBracket(*mathExpression) && !isOpeningBracket(obj) ) { return 0; }
            if ( isClosingBrace(*mathExpression) && !isOpeningBrace(obj) ) { return 0; }
        }
        mathExpression++;
    }
    if (!isEmpty(&stack)) { return 0; }

    return 1;
}
