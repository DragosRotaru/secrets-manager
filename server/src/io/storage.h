#include "../utils/either.h"

#ifndef STORAGE_H
#define STORAGE_H

TypeDefErrEither(int, ValidateBaseDirResult);
ValidateBaseDirResult validateBaseDir(const char* dirPath);
char* readFile(const char* fileName);
int writeFile(const char* string, const char* fileName);

#endif