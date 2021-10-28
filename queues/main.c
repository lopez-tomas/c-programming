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
//    } else {
//        puts("queue has space.\n");
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
//    if( isEmpty(&queue) ) {
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


    puts("Movements file:\n");
    showFile(movements_all__filename, &mov, sizeof(mov), showMovement);

    puts("");

//    get_code = obtainingMovementsFiles(movements_all__filename, movements_greater__filename, movements_minor__filename);
//    switch( get_code ) {
//        case MOV_ALL__ERR:
//            printf("Error opening %s file.\n", movements_all__filename);
//            return MOV_ALL__ERR;
//
//        case MOV_GREATER__ERR:
//            printf("Error creating %s file.\n", movements_greater__filename);
//            return MOV_GREATER__ERR;
//
//        case MOV_MINOR__ERR:
//            printf("Error creating %s file.\n", movements_minor__filename);
//            return MOV_MINOR__ERR;
//
//        case PUSH_QUEUE__ERR:
//            puts("Error pushing movement into queue.");
//            return PUSH_QUEUE__ERR;
//
//        case SUCCESS:
//            puts("Everything worked!");
//    }

    puts("");

    printf("Movements greater or equal than %d:\n\n", MAX_VALUE);
    showFile(movements_greater__filename, &mov, sizeof(mov), showMovement);

    puts("\n");

    printf("Movements minor than %d:\n\n", MAX_VALUE);
    showFile(movements_minor__filename, &mov, sizeof(mov), showMovement);

    return 0;
}
