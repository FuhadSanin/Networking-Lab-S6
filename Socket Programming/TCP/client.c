#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include <netdb.h>
#include <netinet/in.h>
#include <sys/types.h>

int main()
{
    int clientsocket, serversocket, port;
    struct sockaddr_in serveraddr;
    socklen_t len;
    char messages[20];

    clientsocket = socket(AF_INET, SOCK_STREAM, 0);

    bzero((char *)&serveraddr, sizeof(serveraddr));
    len = sizeof(serveraddr);

    serveraddr.sin_family = AF_INET;
    printf("Enter the Port: ");
    scanf("%d", &port);
    serveraddr.sin_port = htons(port);

    connect(clientsocket, (struct sockaddr_in *)&serveraddr, sizeof(serveraddr));
    send(clientsocket, "HI I'm Client", sizeof("HI I'm Client"), 0);
    recv(clientsocket, messages, sizeof(messages), 0);
    printf("\nClient Message : %s\n", messages);

    close(clientsocket);
}

// 1.(7) Libraries
// 2.Initialise (clientsocket,serversocket), sockaddr = (serveraddr,clientaddr), socklen_t -> len , messages
// 3.Client Socket
// 4.Clear ServerAddress
//      4.1 len
//      4.2 sin_family
//      4.3 sin_port
