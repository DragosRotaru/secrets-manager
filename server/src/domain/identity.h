#include "id.h"

#ifndef IDENTITY_H
#define IDENTITY_H

typedef struct {
    ID id;
    int sessionExpiry;  // -1 = sessionless
    char* name;
    char* password;
    ID* grantedSecrets[];
} Identity;


#endif
