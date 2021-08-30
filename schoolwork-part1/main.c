#ifdef _WIN32
#define CLEAR "cls"
#else // In any other OS
#define CLEAR "clear"
#endif

//#include <windows.h> -> Use it for Windows
#include "main.h"

int main() {
    /// Exercise 1 - Factorial
    unsigned int numberToFactor; // It could be 0
    unsigned long long int factoredNumber;

    /// Exercise 2 - Combinatorial
    int numberN,
        numberM;
    unsigned long long int combinatorial;

    /// Exercise 3 - Natural Exponential
    int numberX;
    double tol,
           naturalExponential,
           naturalExponentialWithMath;

    /// Exercise 4 - Square Root
    int numberRoot;
    double tolRoot,
           squareRootOfNumber;

    /// Exercise 5 - Fibonacci;
    int integerNumber,
        answerFibonacci;

    /// Exercise 6 - Sinus
    int numberSinus;
    double tolSinus,
           sinusOfNumber;

    /// Exercise 7 - Classification
    int numberToClassify,
        classifiedNumber;

    /// Exercise 8 - Successive Sums
    int numberA,
        numberB;
    unsigned long long int result;

    exerciseTitle("Exercise 1 - Calculate factorial of number entered by user.");
    do {
        numberToFactor = enterNumberToFactor();
        factoredNumber = factorialOf(numberToFactor);

        printFactoredNumber(numberToFactor, factoredNumber);
    } while( continueOperating() == 'y' );

    exerciseTitle("Exercise 2 - Calculate combinatorial of m with n.");
    do {
        numberN = enterNumberN();
        numberM = enterNumberM(numberN);
        combinatorial = combinatorialOf(numberN, numberM);

        printf("Combinatorial of %d with %d is %llu", numberM, numberN, combinatorial);
    } while( continueOperating() == 'y' );

    exerciseTitle("Exercise 3 - Calculate e^x with a given X and a TOL.");
    do {
        numberX = enterNumber();
        tol = enterTol();

        naturalExponential = calculateNaturalExponential(numberX, tol);
        naturalExponentialWithMath = calculateNaturalExponentialWithMath(numberX, tol);
        printf("e^%d with a TOL: %lf is %lf\n", numberX, tol, naturalExponential);
        printf("e^%d with a TOL: %lf is %lf", numberX, tol, naturalExponentialWithMath);
    } while( continueOperating() == 'y' );

    exerciseTitle("Exercise 4 - Calculate square root of a given number and TOL.");
    do {
        numberRoot = numberForRoot();
        tolRoot = enterTol();

        squareRootOfNumber = squareRootOf(numberRoot, tolRoot);
        printf("square root of %d with TOL: %lf is %lf", numberRoot, tolRoot, squareRootOfNumber);
    } while ( continueOperating() == 'y' );

    exerciseTitle("Exercise 5 - Determine if a given integer number is in Fibonacci Sequence.");
    do {
        integerNumber = enterInteger();
        answerFibonacci = isInFibonacci(integerNumber);
        printAnswerFibonacci(integerNumber, answerFibonacci);
    } while ( continueOperating() == 'y' );

    exerciseTitle("Exercise 6 - Calculate sinus of a given number and TOL.");
    do {
        numberSinus = numberForSinus();
        tolSinus = enterTol();

        sinusOfNumber = sinusOf(numberSinus, tolSinus);
        printf("sinus of %d with TOL: %lf is %lf", numberSinus, tolSinus, sinusOfNumber);
    } while ( continueOperating() == 'y' );

    exerciseTitle("Exercise 7 - Determine if a given number is PERFECT, DEFICIENT or ABUNDANT.");
    do {
        numberToClassify = enterInteger();
        classifiedNumber = numberClassification(numberToClassify);

        printClassification(numberToClassify, classifiedNumber);
    } while ( continueOperating() == 'y' );

    exerciseTitle("Exercise 8 - Calculate the product of two natural numbers with Successive Sums.");
    do {
        numberA = enterNaturalNumber();
        numberB = enterNaturalNumber();
        result = productWithSuccessiveSums(numberA, numberB);

        printf("%d x %d = %llu", numberA, numberB, result);
    } while( continueOperating() == 'y' );

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
