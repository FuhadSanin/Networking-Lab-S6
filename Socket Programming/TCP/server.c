#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
int prime(int n)
{
    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    int serversocket, clientsocket, port, number;
    struct sockaddr_in serveraddr, clientaddr;
    socklen_t len;
    char message[50];
    struct serveraddr;

    serversocket = socket(AF_INET, SOCK_STREAM, 0);
    bzero((char *)&serveraddr, sizeof(serveraddr));

    serveraddr.sin_family = AF_INET;
    printf("Enter the port number\n");
    scanf("%d", &port);

    serveraddr.sin_port = htons(port);
    serveraddr.sin_addr.s_addr = INADDR_ANY;
    bind(serversocket, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
    bzero((char *)&clientaddr, sizeof(clientaddr));
    len = sizeof(clientaddr);

    listen(serversocket, 5);

    printf("Waiting for client connection\n");

    clientsocket = accept(serversocket, (struct sockaddr *)&clientaddr, &len);
    printf("\nclient connectivity received\n");

    write(clientsocket, "ENTER A NUMBER", sizeof("ENTER A NUMBER"));
    read(clientsocket, &number, sizeof(number));

    if (prime(number) == 1)
        write(clientsocket, "The number is not prime", sizeof("The number is not prime"));
    else
        write(clientsocket, "The number is prime", sizeof("The number is prime"));
        
    close(clientsocket);
    close(serversocket);
}