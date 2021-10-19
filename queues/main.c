#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main() {
//    int vec[] = {1, 2, 3, 4, 5};
//    int elem;
//    int i;
//
//    t_Queue queue;
//
//    createQueue(&queue);
//
//    if( isEmpty(&queue) ) {
//        puts("queue is empty.\n");
//    } else if( isFull(&queue, sizeof(int)) ) {
//        puts("queue is full.\n");
//    }
//
//    for(i = 0; i < sizeof(vec) / sizeof(int); i++) {
//        push(&queue, &vec[i], sizeof(int));
//    }
//
//    if( isEmpty(&queue) ) {
//        puts("queue is empty.\n");
//    } else if( isFull(&queue, sizeof(int)) ) {
//        puts("queue is full.\n");
//    } else {
//        puts("queue has space.\n");
//    }
//
//    pop(&queue, &elem, sizeof(int));
//    printf("Pop: %d\n", elem);
//
//    front(&queue, &elem, sizeof(int));
//    printf("Front: %d\n\n", elem);
//
//    emptyQueue(&queue);
//
//     if( isEmpty(&queue) ) {
//        puts("queue is empty.\n");
//    } else if( isFull(&queue, sizeof(int)) ) {
//        puts("queue is full.\n");
//    } else {
//        puts("queue has space.\n");
//    }

    char movements_all__filename[] = "../binaryArchives/archives/movements.dat";
    char movements_greater__filename[] = "archives/movements_greater.dat";
    char movements_minor__filename[] = "archives/movements_minor.dat";

    t_Movements mov;

    int get_code;

    get_code = obtainingMovementsFiles(movements_all__filename, movements_greater__filename, movements_minor__filename);

    if( get_code == MOV_ALL__ERR || get_code == MOV_GREATER__ERR || get_code == MOV_MINOR__ERR ) {
        puts("Error opening/creating files.");
        return -1;

    } else if( get_code == PUSH_QUEUE__ERR ) {
        puts("Error pushing movements into queue.");
        return -2;

    } else {
        printf("Movements file (original):\n\n");
        showFile(movements_all__filename, &mov, sizeof(mov), showMovement);

        puts("");

//        printf("Movements greater or equal than %d:\n\n", MAX_VALUE);
//        showFile(movements_greater__filename, &mov, sizeof(mov), showMovement);
//
//        puts("");
//
//        printf("Movements minor than %d:\n\n", MAX_VALUE);
//        showFile(movements_minor__filename, &mov, sizeof(mov), showMovement);
    }

    return 0;
}
