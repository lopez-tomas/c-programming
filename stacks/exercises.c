#include <string.h>
#include "exercises.h"
#include "../schoolwork-part1/macros.h"

#define IS_OPENING_PARENTHESIS(c) ( (c) == '(' )
#define IS_CLOSING_PARENTHESIS(c) ( (c) == ')' )

#define IS_OPENING_BRACKET(c) ( (c) == '[' )
#define IS_CLOSING_BRACKET(c) ( (c) == ']' )

#define IS_OPENING_BRACE(c) ( (c) == '{' )
#define IS_CLOSING_BRACE(c) ( (c) == '}' )

#define IS_OPENNESS(c) ( IS_OPENING_PARENTHESIS(c) || IS_OPENING_BRACKET(c) || IS_OPENING_BRACE(c) )
#define IS_CLOSURE(c) ( IS_CLOSING_PARENTHESIS(c) || IS_CLOSING_BRACKET(c) || IS_CLOSING_BRACE(c) )

int isMathExpressionCorrect(const char* mathExpression) {
    t_Stack stack;
    char obj;

    createStack(&stack);

    while(*mathExpression) {
        if( IS_OPENNESS(*mathExpression) ) {
            push(&stack, mathExpression, sizeof(char));
        }

        if( IS_CLOSURE(*mathExpression) ) {
            if(isEmpty(&stack)) {
                return 0;
            }

            pop(&stack, &obj, sizeof(char));
            if( IS_CLOSING_PARENTHESIS(*mathExpression) && !IS_OPENING_PARENTHESIS(obj) ) { return 0; }
            if( IS_CLOSING_BRACKET(*mathExpression) && !IS_OPENING_BRACKET(obj) ) { return 0; }
            if( IS_CLOSING_BRACE(*mathExpression) && !IS_OPENING_BRACE(obj) ) { return 0; }
        }
        mathExpression++;
    }
    if(!isEmpty(&stack)) { return 0; }

    return 1;
}

void addTwoNumbers(const char* numberA, const char* numberB, t_Stack* result) {
    unsigned numberA_length = strlen(numberA);
    unsigned numberB_length = strlen(numberB);

    /// Auxiliar
    char* greater_string;
    char char_greater_string;

    char* minor_string;
    char char_minor_string;

    /// Stacks and digits variables
    t_Stack greater_number_stack;
    int greater_number_digit;

    t_Stack minor_number_stack;
    int minor_number_digit;

    int result_digit;
    int carry = 0;

    /// I need to know which is greater between numberA & numberB
    if(numberA_length > numberB_length) {
        greater_string = (char*)numberA;
        minor_string = (char*)numberB;
    } else {
        greater_string = (char*)numberB;
        minor_string = (char*)numberA;
    }

    /// Creating each stack
    createStack(&greater_number_stack);
    createStack(&minor_number_stack);

    while(*greater_string) {
        char_greater_string = *greater_string;

        if( !IS_NUMBER(char_greater_string) ) {
            emptyStack(&greater_number_stack);
            return;
        }

        greater_number_digit = char_greater_string - '0';

        /*if( !push(&greater_number_stack, greater_string, sizeof(char)) ) {*/
        if( !push(&greater_number_stack, &greater_number_digit, sizeof(int)) ) {
            emptyStack(&greater_number_stack);
            return;
        }
        greater_string++;
    }

    while(*minor_string) {
        char_minor_string = *minor_string;

        if( !IS_NUMBER(char_minor_string) ) {
            emptyStack(&greater_number_stack);
            emptyStack(&minor_number_stack);
            return;
        }

        minor_number_digit = char_minor_string - '0';

        /*if( !push(&minor_number_stack, minor_string, sizeof(char)) ) {*/
        if( !push(&minor_number_stack, &minor_number_digit, sizeof(int)) ) {
            emptyStack(&greater_number_stack);
            emptyStack(&minor_number_stack);
            return;
        }
        minor_string++;
    }

    while( !isEmpty(&minor_number_stack) ) {
        /*pop(&minor_number_stack, &minor_number_digit_char, sizeof(char));*/
        /*pop(&greater_number_stack, &greater_number_digit_char, sizeof(char));*/
        pop(&minor_number_stack, &minor_number_digit, sizeof(int));
        pop(&greater_number_stack, &greater_number_digit, sizeof(int));

        /*greater_number_digit = greater_number_digit_char - '0';*/
        /*minor_number_digit = minor_number_digit_char - '0';*/

        result_digit = minor_number_digit + greater_number_digit + carry;

        if(result_digit >= 10) {
            result_digit %= 10;
            /*result_digit_char = (char)result_digit;*/
            carry = 1;
        } else {
            /*result_digit_char = (char)result_digit;*/
            carry = 0;
        }

        /*if ( !push(result, &result_digit_char, sizeof(char)) ) {*/
        if( !push(result, &result_digit, sizeof(int)) ) {
            emptyStack(&greater_number_stack);
            emptyStack(&minor_number_stack);
            emptyStack(result);

            return;
        }
    }

    while( !isEmpty(&greater_number_stack) ) {
        /*pop(&greater_number_stack, &greater_number_digit_char, sizeof(char));*/
        pop(&greater_number_stack, &greater_number_digit, sizeof(int));

        /*greater_number_digit = greater_number_digit_char - '0';*/

        result_digit = greater_number_digit + carry;

        if(result_digit >= 10) {
            result_digit %= 10;
            /*result_digit_char = (char)result_digit;*/
            carry = 1;
        } else {
            /*result_digit_char = (char)result_digit;*/
            carry = 0;
        }

        /*if ( !push(result, &result_digit_char, sizeof(char)) ) {*/
        if( !push(result, &result_digit, sizeof(int)) ) {
            emptyStack(&greater_number_stack);
            emptyStack(&minor_number_stack);
            emptyStack(result);

            return;
        }
    }
}
