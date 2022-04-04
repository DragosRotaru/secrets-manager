#include <stdio.h>
#include "user-input.h"
#include "hardware-key.h"
#include "master-auth.h"

MasterAuth getMasterAuth() {
    printf("Please enter a master password:\n");
    char* masterPassword = getUserInput();
    char* hardwareKey;
    while (hardwareKey == NULL)
    {   printf("Please plug in your hardware key:\n");
        hardwareKey = getHardwareKey();
        waitUserInput();
        if (hardwareKey == NULL) {
            printf("Key not detected!\n");
        }
    }
    printf("Key detected!\n");
    return (MasterAuth){ .password = masterPassword, .key = hardwareKey };
}
