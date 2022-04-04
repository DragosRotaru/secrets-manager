#include "id.h"

#ifndef SECRET_H
#define SECRET_H

typedef struct {
    ID id;
    char* name;
    char* secret;
} Secret;

#endif