#include "../utils/either.h"

#ifndef STORAGE_H
#define STORAGE_H

TypeDefErrEither(int, ValidateBaseDirResult);
ValidateBaseDirResult validateBaseDir();
char* readFile(char* fileName);
int writeFile(char* string, char* fileName);

#endif