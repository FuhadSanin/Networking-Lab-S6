#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <netdb.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX 50
#define PORT 3000

int main()
{

    int clientsocket, serversokcet, n;
    struct sockaddr_in serveraddr, clientaddr;
    struct hostent *server;
    char send[MAX], recvline[MAX];

    clientsocket = socket(AF_INET, SOCK_STREAM, 0);

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(PORT);
    serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(clientsocket, (struct sockaddr *)&serveraddr, sizeof(serveraddr));

    printf("Enter the file name : ");
    scanf("%s", send);

    write(clientsocket, send, MAX);

    while ((n = read(clientsocket, recvline, MAX) != 0))
        printf("%s", recvline);
    printf("\n");

    close(clientsocket);
    return 0;
}
