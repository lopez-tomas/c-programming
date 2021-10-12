#include <stdio.h>
#include <stdlib.h>

#include "archives.h"
#include "decryption.h"

#define ENCRYPTED_LINE__DIM 150

int decryptFile(const char* encrypted_filename, const char* opening_mode__encrypted_file, const char* decrypted_filename) {
    FILE* pEncrypted_file;
    FILE* pDecrypted_file;
    char encrypted__line[ENCRYPTED_LINE__DIM];

    pEncrypted_file = fopen(encrypted_filename, opening_mode__encrypted_file);
    if( !pEncrypted_file ){
        return ERR__ENCRYPTED_FILE;
    }

    pDecrypted_file = fopen(decrypted_filename, "wt");
    if( !pDecrypted_file ) {
        return ERR__DECRYPTED_FILE;
    }

    while( !feof(pEncrypted_file) ) {
        fgets(encrypted__line, ENCRYPTED_LINE__DIM - 1, pEncrypted_file);
        printf("%s", encrypted__line);

        return SUCCESS;
    }

    fclose(pEncrypted_file);
    fclose(pDecrypted_file);

    return SUCCESS;
}
