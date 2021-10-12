#ifndef STRINGFUNCTIONS_H
#define STRINGFUNCTIONS_H

char* str_cpy(char* destiny, char* origin);
unsigned int str_len(char* origin);
char* str_cat(char* destiny, char* origin);
char* str_chr(char* source, char character);
char* str_rchr(char* source, char character);
char* str_lwr(char* source);
char* str_upr(char* source);
int str_cmp(char* source1, char* source2);
int str_cmpi(char* source1, char* source2);
char* noWhiteSpaces(char* source, unsigned int* length);
int isPalindrome(char* source);
long long int numericValueOf(const char* source);

#endif // STRINGFUNCTIONS_H
