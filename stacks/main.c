#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

int main() {
    /*int vec[] = {1, 3, 2, 4};*/
    /*int i;*/
    /*t_Stack stack;*/
    /*int data;*/

    /*createStack(&stack);*/

    /*for(i = 0; i < 4; i++) {*/
        /*push(&stack, &vec[i], sizeof(int));*/
    /*}*/
    /*if (top(&stack, &data, sizeof(int))) {*/
        /*printf("Top: %d\n\n", data);*/
    /*}*/

    /*while(pop(&stack, &data, sizeof(int))) {*/
        /*printf("%d\t", data);*/
    /*}*/

    /*printf("\n\nDone!\n");*/

    char cad[200];
//    strcpy(cad, "{[()]}"); // Case 1
    strcpy(cad, "{[()]})"); // Case 2
//    strcpy(cad, "()}()"); // Case 3
//    strcpy(cad, "{{[[]()[]{}]}}"); // Case 4
//    strcpy(cad, "{{[[]()[]{}}]}"); // Case 5
    strcpy(cad, "{[(3 + 1)] * x + [2 * (1 + 5)]}"); // Case 6

    printf("The math expression is: %s", cad);
    if(isMathExpressionCorrect(cad)) {
        printf("\nThe given math expression is correct.\n");
    } else {
        printf("\nThe given math expression is incorrect.\n");
    }

    return 0;
}
