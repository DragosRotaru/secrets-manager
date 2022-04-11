# Vault

## External Dependencies

For this system to be secure, the following must also be secure

- NameCheap
    - CloudFlare
        - LetsEncrypt
- Phone
    - Android
        - Firefox
            - (client)
- Laptop
    - MacOS
        - Parallels VM
            - NixOS
                - (server)
        - FireFox
            - (client)
- Remote Host?
    - ...
        - (server)

## API Endpoints

	/getSessionToken
    /getAccountByName
        returns username, password
	/getAccountsByURL
		returns username, password
	/getAccount2FAByID
		returns TOTP Code
	/generatePassword
		returns Password
	/replacePasswordByID
		saves Password

## Server

- Server boots with master password and hardware key required at startup
- Runs on linux inside a VM and in the cloud
- It listens to a port exposed to the Host machine and communicates via TLS with a LetsEncrypt Cert
- If no session has been produced in 48 hours, the server shuts down
- After 30 days, server shuts down regardless
- Data is stored in a file encrypted with the master password and hardware key
- Admin operations are performed by via the server executable
- Server connects to backup server to push encrypted volume on every state change

### Client

- Firefox Extension for Mobile and Desktop
- Server URL is provided in the config section
- Identity with Password must be provided to login and start a session with a preset expiry

#### UI

Home View
- Search Bar: Get account or secret by Name with enter button
    - Shows Account
    - Automatically Clears view and data after 10 seconds
- Button: Get accounts for current URL
    - Shows Table of Name, Username, Password, copy to clipboard buttons, TOTP, change password?
        -> if change password clicked, show password, copy to clipboard and confirm or cancel
    - Automatically Clears view and data after 10 seconds
- Button: Replace

#### CLI

`vault get secret <ID>`
`vault get account.username <ID>`
`vault get account.password <ID>`

Identity with a password is provided to the CLI via VAULT_CLI_IDENTITY and VAULT_CLI_PASSWORD

## Network

- Authoritative DNS for vault.rotaru.co points to remote server static IP 
- Claude Net Recursive Resolver DNS sets vault.rotaru.co to point to Macbook static IP
- Hosts file on Macbook Pro sets vault.rotaru.co to point to VM IP
- set static VM IP and forward traffic from mac with a reverse proxy when connected to CLaude
- LetsEncrypt renews cert automatically on the remote server

## SSH Keys

- maintain 1 SSH key per identity and strip comment in pub key
- for git deployments, use read-only access tokens

## Data Recovery, Availability

- macbook has offline access
- phone client has LAN access if on the Claude network or remote access if online
- changes to the vault can only be made with a connection to the backup server
- backup server api is idempotent and non-destructive. backup server code cron job retains correct number of copies and distributes them
- credentials to the backup server are stored encrypted
- The Linux VM is responsible for backups of the software, config and codebase
- The Host is responsible for VM Image backups

1. 3 copies of key         - person, parents, viv
2. 3 copies of password    - brain
3. 5 copies of data        - laptop, claude, viv, cloud, parents
4. 5 copies of source code - laptop, claude, viv, cloud, parents
5. recovery instructions   - viv, parents

## Recovery Site

1. dead mans switch option
2. SO logs in with their password
3. multi-party option (AND OR operations)
4. as soon as they log in with their password it notifies you
5. they see the instructions you wanted to leave with them
6. option to wait another x days before releasing info
7. option to confirm with a call
8. option to confirm with a piece of ID, death certificate or evidence of kidnapping/imprisonment

## Future Features

- keep track of recovery options and associated emails (when not the same as username)
- keep track of tags
- command to print out duplicate passwords
- command to print out accounts by associated email
- command to print out accounts by password age