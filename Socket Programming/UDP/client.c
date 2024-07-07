#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include <netdb.h>
#include <netinet/in.h>
#include <sys/types.h>

int main()
{
    int clientsocket, serversocket, port, number;
    struct sockaddr_in serveraddr, clientaddr;
    socklen_t len;
    char messages[20];

    clientsocket = socket(AF_INET, SOCK_DGRAM, 0);

    bzero((char *)&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    printf("Enter the port : ");
    scanf("%d", &port);
    serveraddr.sin_port = htons(port);
    len = sizeof(serveraddr);

    printf("\nWaiting For connenction \n");
    if (connect(clientsocket, (struct sockaddr *)&serveraddr, len) < 0)
        printf("Connection Successfull ..!!");
    else
        printf("Connection Failed ..!!");

    printf("Enter the number");
    scanf("%d", &number);
    sendto(clientsocket, &number, sizeof(number), 0, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
    recvfrom(clientsocket, messages, sizeof(messages), 0, (struct sockaddr *)&serveraddr, &len);
    printf("Client Message: %s", messages);

    close(clientsocket);
}
