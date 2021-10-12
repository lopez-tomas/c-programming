#ifndef ARCHIVES_H
#define ARCHIVES_H

#define ERR -1
#define SUCCESS 100
#define ERR__ENCRYPTED_FILE 200
#define ERR__DECRYPTED_FILE 300
#define ERR__READING_FILE 400
#define ERR__DECRYPTING_FILE 500

int readTextFile(const char* filename);
int decryptFile(const char* encrypted_filename, const char* opening_mode__encrypted_file, const char* decrypted_filename);

#endif // ARCHIVES_H
