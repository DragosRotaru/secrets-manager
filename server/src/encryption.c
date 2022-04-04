#include <string.h>
#include "io/master-auth.h"

// OpenSSL or GPG for encrypting data at rest using aes-256-gcm, pbkdf2
// https://www.linuxjournal.com/content/flat-file-encryption-openssl-and-gpg

char* derivePrivateKeyFromMasterAuth(MasterAuth masterAuth) {
    char* result;
    strcat(masterAuth.password, result);
    strcat(masterAuth.key, result);
    return result;
}

char* encrypt(const char* content, MasterAuth masterAuth) {
    return "";
}

const char* decrypt(const char* content, MasterAuth masterAuth) {
    return "";
}