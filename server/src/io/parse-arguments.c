#include <stdio.h>
#include <string.h>
#include "parse-arguments.h"

// This function parses the first argument and returns the Command
ParseCommandResult parseCommand(const char* command) {
    if (strcmp(command, "initialize"))
    {
        return (ParseCommandResult){ .right = Initialize };
    }
    else if (strcmp(command, "import"))
    {
        return (ParseCommandResult){ .right = Import };
    }
    else if (strcmp(command, "serve"))
    {
        return (ParseCommandResult){ .right = Serve };
    }
    else if (strcmp(command, "help"))
    {
        return (ParseCommandResult){ .right = Help };
    }
    else if (strcmp(command, "version"))
    {
        return (ParseCommandResult){ .right = Version };
    }
    else
    {
        return (ParseCommandResult){ .left = { .code = 1, .message = "command not recognized"} };
    }
}

// This function parses command line arguments
ParseArgsResult parseArguments (int argc, char const* argv[])
{
    
    // No Command Provided
    if (argc < 2) {
        return (ParseArgsResult){ .left = { .code = 2, .message = "no command provided"} };
    }
    
    // Return Value
    ProgramArgs programSettings;

    // Parse the command
    ParseCommandResult res = parseCommand(argv[1]);
    if (res.left.code) {
        return (ParseArgsResult){ .left = res.left };
    } else {
        programSettings.command = res.right;
    }

    if (programSettings.command == Help || programSettings.command == Version ) {
        return (ParseArgsResult){ .right = programSettings };
    }

    // Parse the Base Directory Path

    // No BaseDirPath Provided
    if (argc < 3) {
        return (ParseArgsResult){ .left = { .code = 3, .message = "no base directory path specified, or specified in wrong order"} };
    }

    programSettings.baseDirPath = argv[2];

    if (programSettings.command == Initialize) {
       return (ParseArgsResult){ .right = programSettings };
    }
    
    if (programSettings.command == Import) {
        // No csvFilePath Provided
        if (argc < 4) {
            return (ParseArgsResult){ .left = { .code = 4, .message = "no csv import file path specified, or specified in wrong order"} };
        }
        programSettings.csvFilePath = argv[3];
        return (ParseArgsResult){ .right = programSettings };
    }
    
    if (programSettings.command == Serve) {
        if (argc == 4 && strcmp(argv[3], "--read-only")) {
            programSettings.readOnly = true;
            return (ParseArgsResult){ .right = programSettings };
        } else {
            return (ParseArgsResult){ .left = { .code = 5, .message = "option not recognized"} };
        }
    }

    return (ParseArgsResult){ .left = { .code = 6, .message = "something went wrong parsing your arguments"} };
} 