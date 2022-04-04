// https://www.beej.us/guide/bgc/

#include <stdio.h>
#include "io/parse-arguments.h"
#include "io/storage.h"
#include "io/master-auth.h"
#include "vault.h"
#include "commands/import.h"
#include "commands/initialize.h"
#include "commands/serve.h"

int main(int argc, char const* argv[])
{
    static const char* helpMessage =  "execute `vault-server help` for more information.";
    static const char* semVer = "0.0.1";
    // TODOmmanual.md
    const char* manual = "";
    
    // Parse arguments
    const ParseArgsResult parseArgsResult = parseArguments(argc, argv);
    if (parseArgsResult.left.code) {
        printf("%s. %s\n", parseArgsResult.left.message, helpMessage); 
        return -1;
    }


    const ProgramCommands command = parseArgsResult.right.command;

    // Execute simple commands
    if (command == Help) {
        printf("%s\n", manual); 
        return 0;
    }
    if (command == Version) {
        printf("%s\n", semVer);
        return 0;
    }

    // Validate Base Directory Path
    const char* baseDirPath = parseArgsResult.right.baseDirPath;
    const ValidateBaseDirResult validateBaseDirResult = validateBaseDir(baseDirPath);
    if (validateBaseDirResult.left.code) {
        printf("%s. %s\n", validateBaseDirResult.left.message, helpMessage); 
        return -1;
    }

    // Execute complex commands
    if (command == Initialize) {
        initialize(baseDirPath);
        return 0;
    }

    // TODO loop if password incorrect
    const MasterAuth masterAuth = getMasterAuth();
    const LoadVaultResult loadVaultResult = loadVault(baseDirPath, masterAuth);
    if (loadVaultResult.left.code) {
        return -1;
    }
    const Vault vault = loadVaultResult.right;

    if (command == Import) {
        import(vault, parseArgsResult.right.csvFilePath);
    }

    if (command == Serve) {
        serve(vault, parseArgsResult.right.readOnly);
    }

    return 0;
}
