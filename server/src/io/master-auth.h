#include <stdio.h>

#ifndef MASTER_AUTH_H
#define MASTER_AUTH_H

typedef struct {
    char* password;
    char* key;
} MasterAuth;

MasterAuth getMasterAuth();

#endif
