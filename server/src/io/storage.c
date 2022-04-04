#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include "storage.h"

ValidateBaseDirResult validateBaseDir(const char* dirPath) {
    DIR* dir = opendir(dirPath);
    if (dir) {
        /* Directory exists. */
        closedir(dir);
        // All Good
        return (ValidateBaseDirResult){ .right = 0 };
    } else if (ENOENT == errno) {
        // Does not Exist
        return (ValidateBaseDirResult){ .left = { .code = 7, .message = "base_dir_path does not exist"} };
    } else if (ENOTDIR == errno) {
        // Not a Directory
        return (ValidateBaseDirResult){ .left = { .code = 8, .message = "base_dir_path is not a directory"} };
    } else if (EACCES == errno) {
        // No Read Permissions
        return (ValidateBaseDirResult){ .left = { .code = 9, .message = "cannot read from base_dir_path"} };
    } else {
        return (ValidateBaseDirResult){ .left = { .code = 9, .message = "error validating base_dir_path"} };
    }

}

char* readFile(const char* fileName) {
   char* buffer = NULL;
   int string_size, read_size;
   FILE* handler = fopen(fileName, "r");

   if (handler)
   {
       // Seek the last byte of the file
       fseek(handler, 0, SEEK_END);
       // Offset from the first to the last byte, or in other words, filesize
       string_size = ftell(handler);
       // go back to the start of the file
       rewind(handler);

       // Allocate a string that can hold it all
       buffer = (char*) malloc(sizeof(char)* (string_size + 1) );

       // Read it all in one operation
       read_size = fread(buffer, sizeof(char), string_size, handler);

       // fread doesn't set it so put a \0 in the last position
       // and buffer is now officially a string
       buffer[string_size] = '\0';

       if (string_size != read_size)
       {
           // Something went wrong, throw away the memory and set
           // the buffer to NULL
           free(buffer);
           buffer = NULL;
       }

       // Always remember to close the file.
       fclose(handler);
    }

    return buffer;
}

int writeFile(const char* string, const char* fileName) {
    // Open a file for writing. 
    // (This will replace any existing file. Use "w+" for appending)
    FILE* file = fopen("fileName", "w");

    int results = fputs(string, file);
    if (results == EOF) {
        return -1;
    }
    fclose(file);
    return 0;
}