#include <stdio.h>
#include <stdlib.h>
#include "../vault.h"
#include "../io/user-input.h"
#include "../io/master-auth.h"

// TODO add retry and input validation
SaveVaultResult initialize(const char* baseDirPath) {
    printf("Creating Vault...\n");
    // TODO separate createMasterAuth which includes re-entering password
    const MasterAuth masterAuth = getMasterAuth();
    const Vault vault = createVault();
    // TODO implement defaults
    printf("Enter a maximum login session length in number of minutes for all Identities before having to reauthenticate (default = 30, 0 = no limit):\n");    
    vault.settings->MAX_SESSION_LENGTH = atoi(getUserInput());
    printf("Enter a maximum number of hours elapsed since last login before server requires master reauthentication (default = 48, 0 = no limit):\n");    
    vault.settings->MAX_HOURS_ELAPSED_LAST_LOGIN = atoi(getUserInput());
    printf("Enter a maximum number of days until server requires master reauthentication (default = 30, 0 = no limit):\n");
    vault.settings->MAX_DAYS_ELAPSED = atoi(getUserInput());
    printf("Vault initialized successfully, saving and closing now.\n");
    return saveVault(baseDirPath, masterAuth, vault);
}