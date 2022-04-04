#include "utils/either.h"
#include "io/master-auth.h"

#ifndef VAULT_H
#define VAULT_H

typedef struct {
     int MAX_SESSION_LENGTH;
     int MAX_DAYS_ELAPSED;
     int MAX_HOURS_ELAPSED_LAST_LOGIN;
} VaultSettings;

typedef struct {
    void* identities;
    void* secrets;
    void* accounts;
    VaultSettings* settings;
} Vault;


Vault createVault();

const char* serializeVault(Vault vault);

Vault deserializeVault(const char* serialized);

TypeDefErrEither(Vault, LoadVaultResult);
LoadVaultResult loadVault(const char* fileName, MasterAuth masterAuth);

TypeDefErrEither(int, SaveVaultResult);
SaveVaultResult saveVault(const char* fileName, MasterAuth masterAuth, Vault vault);

#endif