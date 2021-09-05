### Arrays: Vectors

```c
int vec1[5] = {1,2,3,4,5};
int vec2[5] = {10,11,12};                // compiler completes with 0s into pos 3 and pos 4.
int vec3[5] = {21,22,23,24,25,26,27,28}; // compiler does not take in account pos 5 onwards.
int vec4[] = {31, 32, 33};               // compiler assings TAM.
int vec5[];                              // it don't have TAM so compiler throws error.
int vec6[5] = {41, , 42, 43, 44};        // it can't assign 0 in pos 1 because I put more values after. Compilers throws error.
int vec7[5] = {0};                       // compiler initializes all with 0s.
vec3[6] = 7;
```

### Pointers ###

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

### printArray() test ###

```c
int vec[] = {1,2,3,4,5,6,7};
int cant = 7;

printf("%p\n", &vec);
printf("Vector vec[]: \n\n");
printArray(vec, cant, sizeof(vec) / TAM_INT);
```

### fillArray() test ###

```c
int vecToFill[100] = {1, 2, 3};
int cantElements = 3;

printf("\nVector vecToFill[]: \n\n");
printArray(vecToFill, cantElements, sizeof(vecToFill) / TAM_INT);

cantElements = fillArray(vecToFill, cantElements, sizeof(vecToFill) / TAM_INT);
printf("\nVector vecToFill[]: \n\n");
printArray(vecToFill, cantElements, sizeof(vecToFill) / TAM_INT);
```

### Vectors of chars ###

#### We created these char vectors to test compiler.
```c
char cad1[10] = "one";
char cad2[10] = {'h', 'e', 'l', 'l', 'o'};
char cad3[] = "three";
char cad8[3] = "two";

char cad4[5] = "constantinopla";
char cad5[] = {'a', , 'b'};
char cad5bis[] = {'a', 'b'};
char cad6[] = "";
char cad6bis[] = " ";
char cad7[10] = "";

char cad9[] = "123";
char cad10[] = { 48, 49, 50, 51, 65, 97, 64 };
char cad11[]= cad8;
```
##### Using this line with each vector we have an answer. Where _X_ is each number.
```c
printf("%s (%d)\n", cadX, (int)sizeof(cadX)); 
```
#### We get these results on console:
* cad1[10]  = "one";
  * string: 'one'
  * sizeof: 10

* cad2[10] = {'h', 'e', 'l', 'l', 'o'};
  * string: 'hello'
  * sizeof: 10

* cad3[] = "three";
  * string: 'three'
  * sizeof: 6 -> Five chars + '\0'

* cad8[3] = "two";
  * string: 'two123' (__Linux__) ___OR___ 'twothree' (__Windows__)
  * sizeof: 3 -> It's the same number we assigned to it.

* cad4[5] = "constantinopla";
  * string: 'const0123Aa@one' (__Linux__) ___OR___ 'consttwothree' (__Windows__)
  * sizeof: 5 -> It's the same number we assigned to it.

* cad5[] = {'a', , 'b'};
  * ___It doesn't compile.___ -> We are not declaring a value into 2nd position.

* cad5bis[]  = {'a', 'b'};
  * string: 'ab ' (__Linux__) ___OR___ 'abconsttwothree' (__Windows__)
  * sizeof: 2 -> It assigned 2 because we have 'a' & 'b' declared inside vector cad5bis[]

* cad6[] = "";
  * string: _nothing_ (because it has no char).
  * sizeof: 1 -> Because we declare cad6[] with ___" "___ so it adds '\0' inside.

* cad6bis[] = " ";
  * string: ' ' (white space)
  * sizeof: 2 -> char white space + '\0'

* cad7[10] = "";
  * string: _nothing_ (because it has no char).
  * sizeof: 10 -> It's the same number we assigned to it.

* cad9[] = "123"
  * string: '123'
  * sizeof: 4 -> Three chars + '\0'

* cad10[] = { 48, 49, 50, 51, 65, 97, 64 };
  * string: '0123Aa@one' (__Linux__) ___OR___ '0123Aa@123' (__Windows__)
  * sizeof: 7

* cad11[] = cad8;
  * ___It doesn't compile.___ -> We can't assign value to arrays in main because they are constant arrays.

