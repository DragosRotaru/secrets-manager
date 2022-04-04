#include <stdlib.h>
#include "utils/either.h"
#include "vault.h"
#include "io/master-auth.h"
#include "io/storage.h"
#include "encryption.h"

/* Constructor Method for Vault */
Vault createVault() {
    return (Vault){ .identities = NULL, .secrets = NULL, .accounts = NULL };
}

/* Serialization and Deserialization Methods */

const char* serializeVault(Vault vault) {
    // TODO define using CSV
    return "";
}

Vault deserializeVault(const char* serialized) {
    // TODO define using CSV
    Vault vault = createVault();
    return vault;
}


/* Repository Methods */

LoadVaultResult loadVault(const char* fileName, MasterAuth masterAuth){
    char* encrypted = readFile(fileName);
    if (!encrypted) {
        return (LoadVaultResult){ .left = { .code = 10, .message = "file could not be read"  } };
    }
    const char* decrypted = decrypt(encrypted, masterAuth);
    free(encrypted);
    return (LoadVaultResult){ .right = deserializeVault(decrypted) };
}

SaveVaultResult saveVault(const char* fileName, MasterAuth masterAuth, Vault vault) {
    const char* serialized = serializeVault(vault);
    const char* encrypted = encrypt(serialized, masterAuth);
    const int writeResult = writeFile(encrypted, fileName);
    if (writeResult < 0 ) {
        return (SaveVaultResult){ .left = { .code = 11, .message = "failed to save vault to local storage" }};
    }
    return (SaveVaultResult){ .right = 0 };
}