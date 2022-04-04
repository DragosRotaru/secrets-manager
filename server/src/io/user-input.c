#include <stdio.h>

char* getUserInput() {
    char* line = NULL;
    size_t len = 0;
    ssize_t lineSize = 0;
    lineSize = getline(&line, &len, stdin);
    // TODO trim whitespace
    return line;
}

void waitUserInput() {
    printf("Press Any Key to Continue\n");
    getchar();
    return;
}