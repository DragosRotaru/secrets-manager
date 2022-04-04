#include "id.h"

#ifndef ACCOUNT_H
#define ACCOUNT_H

typedef enum { SMS, Email, TOTP, Hardware, Other } TwoFactorAuthType;

typedef struct {
    ID id;
    char* name;
    char* username;
    char* password;
    char* url;
    char* passwordUpdatedAt;
    char* updatedAt;
    char* createdAt;
    TwoFactorAuthType twoFactorAuthType;
    char* TOTPSecret;
    char* OTPBackupCodes[];
} Account;

#endif