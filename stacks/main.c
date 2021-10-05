#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main() {
    int vec[] = {1, 3, 2, 4};
    int i;
    t_Stack stack;
    int data;

    createStack(&stack);

    for(i = 0; i < 4; i++) {
        push(&stack, &vec[i], sizeof(int));
    }
    if (top(&stack, &data, sizeof(int))) {
        printf("Top: %d\n\n", data);
    }

    while(pop(&stack, &data, sizeof(int))) {
        printf("%d\t", data);
    }

    printf("\n\nDone!\n");
    return 0;
}
