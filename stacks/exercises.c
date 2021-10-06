#include "exercises.h"
#include "./dynamic/Stack.h"

#define isOpeningParenthesis(c) ( (c) == '(' )
#define isClosingParenthesis(c) ( (c) == ')' )

#define isOpeningBracket(c) ( (c) == '[' )
#define isClosingBracket(c) ( (c) == ']' )

#define isOpeningBrace(c) ( (c) == '{' )
#define isClosingBrace(c) ( (c) == '}' )

#define isOpenness(c) ( isOpeningParenthesis(c) || isOpeningBracket(c) || isOpeningBrace(c) )
#define isClosure(c) ( isClosingParenthesis(c) || isClosingBracket(c) || isClosingBrace(c) )
