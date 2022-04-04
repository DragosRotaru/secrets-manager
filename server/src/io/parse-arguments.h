#include <stdbool.h>
#include "../utils/either.h"

#ifndef PARSE_ARGUMENTS_H
#define PARSE_ARGUMENTS_H

// see manual for details
typedef enum { Initialize, Import, Serve, Help, Version } ProgramCommands;

// See manual for details
typedef struct {
    ProgramCommands command;
    bool readOnly;
    const char* baseDirPath;
    const char* csvFilePath;
} ProgramArgs;

TypeDefErrEither(ProgramCommands, ParseCommandResult);

// This function parses the first argument and returns the Command
ParseCommandResult parseCommand(const char* command);

TypeDefErrEither(ProgramArgs, ParseArgsResult);

// This function parses command line arguments
ParseArgsResult parseArguments (int argc, char const* argv[]);

#endif