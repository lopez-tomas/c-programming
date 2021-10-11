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

int stacking(const char* number, t_Stack* stack) {
    char number__char;

    while(*number) {
        number__char = *number;

        if( !IS_NUMBER(number__char) ) {
            return 0;
        }

        if( !push(stack, &number__char, sizeof(char)) ) {
            return 0;
        }
        number++;
    }
    return 1;
}

void addTwoNumbers(const char* numberA, const char* numberB, t_Stack* result) {
    unsigned numberA_length = strlen(numberA);
    unsigned numberB_length = strlen(numberB);

    /// Auxiliar
    char* greater_string;
    char* minor_string;

    /// Stacks and digits variables
    t_Stack greater_number_stack;
    int greater_number_digit;
    char greater_number_digit_char;

    t_Stack minor_number_stack;
    int minor_number_digit;
    char minor_number_digit_char;

    int result_digit;
    char result_digit_char;
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

    /// Stacking greater number
    if( !stacking(greater_string, &greater_number_stack) ) {
        emptyStack(&greater_number_stack);
    }

    /// Stacking minor number
    if( !stacking(minor_string, &minor_number_stack) ) {
        emptyStack(&greater_number_stack);
        emptyStack(&minor_number_stack);
    }

    while( !isEmpty(&minor_number_stack) ) {
        pop(&minor_number_stack, &minor_number_digit_char, sizeof(char));
        pop(&greater_number_stack, &greater_number_digit_char, sizeof(char));

        greater_number_digit = greater_number_digit_char - '0';
        minor_number_digit = minor_number_digit_char - '0';

        result_digit = minor_number_digit + greater_number_digit + carry;

        if(result_digit >= 10) {
            result_digit %= 10;
            carry = 1;
        } else {
            carry = 0;
        }
        result_digit_char = (char)result_digit;

        if ( !push(result, &result_digit_char, sizeof(char)) ) {
            emptyStack(&greater_number_stack);
            emptyStack(&minor_number_stack);
            emptyStack(result);

            return;
        }
    }

    while( !isEmpty(&greater_number_stack) ) {
        pop(&greater_number_stack, &greater_number_digit_char, sizeof(char));

        greater_number_digit = greater_number_digit_char - '0';

        result_digit = greater_number_digit + carry;

        if(result_digit >= 10) {
            result_digit %= 10;
            carry = 1;
        } else {
            carry = 0;
        }
        result_digit_char = (char)result_digit;

        if ( !push(result, &result_digit_char, sizeof(char)) ) {
            emptyStack(&greater_number_stack);
            emptyStack(&minor_number_stack);
            emptyStack(result);

            return;
        }
    }
}
