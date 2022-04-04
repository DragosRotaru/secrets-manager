# Secrets Manager Server User Manual

## Description

This program serves as a minimal, high security secrets storage and password manager server.
It facilitates the provisioning, storage, backup, creation, management and access control of your
secrets.

For more information, go to the project page and source code repository hosted on github.com:

https://github.com/dragosrotaru/secretsmanager

## Commands

General Usage: `vault-server [COMMAND] <base_dir_path> ... [options]`

Where base_dir_path is the directory where the program will store all of its files.

### initialize

    initialize a brand new deployment of the program

    Usage: `vault-server initialize <base_dir_path>`

### import

    import secrets in CSV format

    `vault-server import <base_dir_path> <csv_filepath> [options]`

    CSV Format:

        CSV should be comma delimited with the following headers

            Name, Secret

### serve 

    start the server

    Usage: `vault-server serve <base_dir_path> [options]`

    Options:

        --read-only: start the server in read-only mode, not allowing any changes to its data or configuration

### help

    prints this manual

    Useage: `vault-server help`

### version

    prints the software version number

    Useage: `vault-server version`