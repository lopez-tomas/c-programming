#include <stdio.h>
#include <stdlib.h>

#include "archives.h"
#include "decryption.h"
#include "stringFunctions.h"

#define LINE__DIM 150
#define DISPLACEMENT 5
#define INVERTED 1
#define NO_INVERTED 0

static char decryption_group[] = "bcdfgaeiou";

int readTextFile(const char* filename) {
    FILE *pf;
    char pf__line[LINE__DIM];

    pf = fopen(filename, "rt");
    if( !pf ) {
        return ERR__READING_FILE;
    }

    fgets(pf__line, LINE__DIM - 1, pf);
    while( !feof(pf) ) {
        printf("%s", pf__line);

        fgets(pf__line, LINE__DIM - 1, pf);
    }
    fclose(pf);

    return SUCCESS;
}

int decryptFile(const char* encrypted_filename, const char* opening_mode__encrypted_file, const char* decrypted_filename) {
    FILE* pEncrypted_file;
    char encrypted__line[LINE__DIM];

    FILE* pDecrypted_file;
    char decrypted__line[LINE__DIM];

    pEncrypted_file = fopen(encrypted_filename, opening_mode__encrypted_file);
    if( !pEncrypted_file ) {
        return ERR__ENCRYPTED_FILE;
    }

    pDecrypted_file = fopen(decrypted_filename, "wt");
    if( !pDecrypted_file ) {
        fclose(pEncrypted_file);
        return ERR__DECRYPTED_FILE;
    }

    fgets(encrypted__line, LINE__DIM - 1, pEncrypted_file);
    while( !feof(pEncrypted_file) ) {
        str_cpy(decrypted__line, decryptionWithDisplacement(encrypted__line, decryption_group, DISPLACEMENT, NO_INVERTED));

        fprintf(pDecrypted_file, "%s", decrypted__line);

        /// I should stack here each word with its length

        fgets(encrypted__line, LINE__DIM - 1, pEncrypted_file);
    }

    fclose(pEncrypted_file);
    fclose(pDecrypted_file);

    return SUCCESS;
}

long long int findLongestWord(const char* filename) {
    FILE* pf;
    char pf__line[LINE__DIM];
    char* line__pointer;
    long long int letters = 0;

    pf = fopen(filename, "rt");
    if( !pf ) {
        return ERR__READING_FILE;
    }

    fgets(pf__line, LINE__DIM - 1, pf);
    while( !feof(pf) ) {
        special_strcpy(line__pointer, pf__line);
        nextWord(line__pointer, &letters);

        fgets(pf__line, LINE__DIM - 1, pf);
    }

    return letters;
}
