#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "main.h"
#define MAX_FACT 170
#define MAX_FACT_TO_PRINT 13

int main()
{
    // Exercise 1 - Variables
    int numberToFactor; // It could be 0
    double factoredNumber;

    // Exercise 3 - Variables
    int numberX;
    float tol;

//    exerciseTitle("Exercise 1 - Calculate factorial of number entered by user.");
//    do {
//        print
//    } while( continueOperating() );

    exerciseTitle("Exercise 3 - Calculate e^x with a given X and a TOL.");
    do {

    } while( continueOperating() );

    return 0;
}

void exerciseTitle(char message[]) {
    system("cls");
    printf("%s\n", message);
}

char continueOperating() {
    char x;

    do {
        printf("Do you want to continue here? [Y/n]: ");
        fflush(stdin);
        scanf("%c", &x);
        printf("\n");

        x = tolower(x);
    } while(x != 'y' && x != 'n');

    return x;
}
