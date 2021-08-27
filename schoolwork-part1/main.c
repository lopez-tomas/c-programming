#ifdef _WIN32
#define CLEAR "cls"
#else // In any other OS
#define CLEAR "clear"
#endif

//#include <windows.h> -> Use it for Windows
#include "main.h"
#define MAX_FACT 170
#define MAX_FACT_TO_PRINT 13

int main() {
    /// Exercise 1 - Variables
    int numberToFactor; // It could be 0
    double factoredNumber;

    /// Exercise 3 - Variables
    int numberX;
    double tol,
           naturalExponential;

    /// Exercise 4 - Variables
    int numberRoot;
    double tolRoot,
           squareRootOfNumber;

    exerciseTitle("Exercise 1 - Calculate factorial of number entered by user.");
    do {
        numberToFactor = enterNumberToFactor(MAX_FACT);
        factoredNumber = factorialOf(numberToFactor);

        printFactoredNumber(numberToFactor, factoredNumber, MAX_FACT_TO_PRINT);
    } while( continueOperating() == 'y' );

    exerciseTitle("Exercise 3 - Calculate e^x with a given X and a TOL.");
    do {
        numberX = enterNumber();
        tol = enterTol();

        naturalExponential = calculateNaturalExponential(numberX, tol);
        printf("e^%d with a TOL: %lf is %lf", numberX, tol, naturalExponential);
    } while( continueOperating() == 'y' );

    exerciseTitle("Exercise 4 - Calculate square root of a given number and TOL.");
    do {
        numberRoot = numberForRoot();
        tolRoot = enterTol();

        squareRootOfNumber = squareRootOf(numberRoot, tolRoot);
        printf("square root of %d with TOL: %lf is %lf", numberRoot, tolRoot, squareRootOfNumber);
    } while ( continueOperating() == 'y' );

    return 0;
}

void exerciseTitle(char message[]) {
//    system("cls"); -> Use it for Windows
//    system("clear"); // -> Use it for Linux
    system(CLEAR);
    printf("%s\n", message);
}

char continueOperating() {
    char x;

    do {
        printf("\n\nDo you want to continue here? [Y/n]: ");
        fflush(stdin);
        scanf(" %c", &x);
        printf("\n");

        x = tolower(x);
    } while(x != 'y' && x != 'n');

    return x;
}
