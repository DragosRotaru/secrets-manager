#include "io/master-auth.h"

#ifndef ENCRYPTION_H
#define ENCRYPTION_H

char* derivePrivateKeyFromMasterAuth(MasterAuth masterAuth);

const char* encrypt(const char* content, MasterAuth masterAuth);

const char* decrypt(const char* content, MasterAuth masterAuth);

#endif