### Arrays: Vectors

```c
int vec1[5] = {1,2,3,4,5};
int vec2[5] = {10,11,12}; // compiler completes with 0s into pos 3 and pos 4.
int vec3[5] = {21,22,23,24,25,26,27,28}; // compiler does not take in account pos 5 onwards.
int vec4[] = {31, 32, 33}; // compiler assings TAM.
int vec5[]; // it don't have TAM so compiler throws error.
int vec6[5] = {41, , 42, 43, 44}; it can't assign a 0 in pos 1 because I put more values after. Compilers throws error.
int vec7[5] = {0}; // compiler initializes all with 0s.
vec3[6] = 7;
```

### Pointers

```c
int *p, x, *pi; // pointer, integer, pointer
x = 1998;
p = &x;

int y;
y = *p;

printf("x = %d ; *p = %d ; y = %d\n", x, *p, y);
printf("&x = %p ; p = %p", &x, p);

p++;

char *c, varC;
c = &varC;
c++; // add 1byte

p -= 3; // Take out 3 int = 12bytes in 32bits arquitecture.

int v[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
p = v;
printf("%d\n", *v);
printf("%d\n", *p);
printf("%d\n\n", v[0]);
```
