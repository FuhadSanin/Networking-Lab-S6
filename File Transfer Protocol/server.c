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
char buff[4096];
FILE *f1;

int main(int arg, char *argv)
{
    int clientsocket, serversocket, len;
    struct sockaddr_in serveraddr, clientaddr;
    char message[MAX];

    serversocket = socket(AF_INET, SOCK_STREAM, 0);

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = INADDR_ANY;
    serveraddr.sin_port = htons(PORT);

    printf("\nBinded");
    bind(serversocket, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
    printf("\nListenening :");
    listen(serversocket, 5);

    len = sizeof(clientaddr);
    clientsocket = accept(serversocket, (struct sockaddr *)&clientaddr, &len);
    close(serversocket);

    read(clientsocket, &message, MAX);
    printf("\nClient Message : File Name : %s\n", message);
    f1 = fopen(message, "r");
    while (fgets(buff, 4096, f1) != NULL)
    {
        write(clientsocket, buff, MAX);
    }
    fclose(f1);
    close(clientsocket);
    return 0;
}