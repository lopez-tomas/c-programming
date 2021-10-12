#ifndef DECRYPTION_H
#define DECRYPTION_H

char* nextWord(char* source, unsigned* wordLength);
void displaceWord(char* wordStart, char* wordEnd, const char* group, int displacement);
int isLetterInGroup(char letter, const char* group);
void invertWord(char* wordStart, char* wordEnd);
void swapCharacters(char* letter1, char* letter2);
char* decryptionWithDisplacement(char* source, const char* group, int displacement, unsigned isInverted);

#endif // DECRYPTION_H
