#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>

#define PORT 8080

int main(int argc, char const* argv[])
{
    int socket_file_descriptor;
    
    int connected_socket;
    long valread;
    
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );
    memset(address.sin_zero, '\0', sizeof address.sin_zero);
    int addrlen = sizeof(address);

    char* content = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello world!";

    // create a socket and return a file descriptor for the socket
    if ((socket_file_descriptor = socket(PF_INET, SOCK_STREAM, 0)) == 0) {
        perror("In socket");
        exit(EXIT_FAILURE);
    }

    // associate a socket with a port and IP address
    if (bind(socket_file_descriptor, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("In bind");
        exit(EXIT_FAILURE);
    }

    // listen for incoming connections on the socket
    if (listen(socket_file_descriptor, 10) < 0) {
        perror("In listen");
        exit(EXIT_FAILURE);
    }

    while (1) {
        // accept a new connection and create a new socket to communicate
        if ((connected_socket = accept(socket_file_descriptor, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0)
        {
            perror("In accept");
            exit(EXIT_FAILURE);
        }
        
        char buffer[30000] = {0};
        valread = read( connected_socket , buffer, 30000);
        printf("%s\n",buffer );
        write(connected_socket , content , strlen(content));
        close(connected_socket);
    }
    return 0;
}