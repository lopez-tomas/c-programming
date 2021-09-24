#ifndef ARCHIVES_H
#define ARCHIVES_H

#include <stdio.h>

int openFile(FILE** pf, char* fileName, char* mode);
int loadStudentsTestLot(char* fileName);

#endif // ARCHIVES_H
