### Arrays: Multidimensional arrays (2 dimensions)

```c
#include <stdio.h>
#include <stdlib.h>
#define FIL 2
#define COL 3

int main() {

    int mat[FIL][COL];  
    // It has trash

    int mat1[FIL][COL] = { 1,2,3,4,5,6 }; 
    // Compiler does { {1,2,3}, {4,5,6} }

    int mat2[FIL][COL] = { {1,2,3}, {4,5,6} }; 
    // Same as mat1

    int mat3[][COL] = { {1,2,3}, {4,5,6} }; 
    // It has COL, so it compiles fine

    int mat4[FIL][] = { {1,2,3}, {4,5,6} }; 
    // It does not have COL, so compiler does not know how to put every

    int mat5[FIL][COL] = { {1,2}, {4} }; 
    // Compiler does { {1,2,0}, {4,0,0} }

    int mat6[FIL][COL] = {}; 
    // Same as mat1/mat2

    int mat7[][] = { {1,2,3}, {4,5,6} }; 
    // Same as mat4

    int mat8[FIL][COL] = { {1, ,3}, {4,5,6} }; 
    // We didn't define a value between two defined values into first array so compiler throws error.

    int mat9[][COL] = {}; 
    // It has trash.

    int mat10[FIL][COL] = { 1,2, {4} }; 
    // Compiler does { {1,2,4},{0,0,0} }

    int mat11[][COL] = { 1,2,3,4,5,6,7 }; 
    // Compiler does { {1,2,3}, {4,5,6}, {7,0,0} }

    int mat12[FIL][COL] = { {}, {4,5,6} }; 
    //

    int mat13[FIL][COL] = { {1,2,3}, {} }; 
    // Compiler does { {1,2,3}, {0,0,0} }

    int mat14[FIL][COL] = {{0}}; 
    // Compiler does { {0,0,0}, {0,0,0} }

    int mat15[][COL] = {0}; 
    // {0,0,0}

    int mat16[][COL]={ {11}, {14, 15, 16}, {17, 18, 19, 20}}; 
    // Compiler does { {11,0,0}, {14,15,16}, {17,18,19}, {20,0,0} }

    int mat17[][COL]={ {4, 6, 8, 6}, {1, 7, 4, 2}, {9, 14, 32, 74}, {10, 45, 14, 7}}; 
    // Compiler does { {4,6,8}, {6,1,7}, {4,2,9}, {14,32,74}, {10,45,14}, {7,0,0} }

    /// ##################
    /// printf lines here!
    /// ##################

    return 0;
}
```

### Inside main() you can use these lines to see memory direction of mat1, &mat1, *mat1, mat1[0], ..., mat1[0][0], ...

```c
printf("Memory direction in mat1: %p\n", mat1);
printf("Memory direction in &mat1: %p\n", &mat1);
printf("Memory direction in *mat1: %p\n", *mat1);

printf("\nMemory direction in mat1[0]: %p\n", mat1[0]);
printf("Memory direction in &mat1[0]: %p\n", &mat1[0]);
printf("Memory direction in *mat1[0]: %p\n", *mat1[0]);

printf("\nMemory direction in mat1[0][0]: %p\n", mat1[0][0]);
printf("Memory direction in &mat1[0][0]: %p\n", &mat1[0][0]);
printf("Memory direction in *mat1[0][0]: %p\n", *mat1[0][0]);

printf("\nMemory direction in **mat1: %p\n", **mat1);
```