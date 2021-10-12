#include "main.h"

int main() {
    char encrypt_filename[] = "archives/ofuscado.txt";
    char encrypt_file__opening_mode[] = "rt";
    char decrypt_filename[] = "archives/desofuscado.txt";
    int wasDecrypted;

    puts("##########################");
    puts("Midterm Exam Demo - Part 1");
    puts("##########################\n");

    puts("Encrypted file:\n");
    readTextFile(encrypt_filename);
    puts("\n");

    wasDecrypted = decryptFile(encrypt_filename, encrypt_file__opening_mode, decrypt_filename);

    if( wasDecrypted == SUCCESS) {
        puts("#################################################################################");
        printf("%s file decrypted. You can read it at %s\n", encrypt_filename, decrypt_filename);
        puts("#################################################################################\n\n");

        puts("Decrypted file:\n");
        readTextFile(decrypt_filename);
        puts("");
    } else {
        puts("##################################################");
        printf("%s file could not be decrypted.\n", encrypt_filename);
        puts("##################################################\n");

        return ERR__DECRYPTING_FILE;
    }

    return 0;
}
