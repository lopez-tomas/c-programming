### Strings: Vectors of chars ###

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