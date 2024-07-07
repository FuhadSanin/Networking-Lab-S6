#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include <netdb.h>
#include <netinet/in.h>
#include <sys/types.h>
int prime(int n)
{
    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int clientsocket, serversocket, number, port;
    struct sockaddr_in serveraddr, clientaddr;
    socklen_t len;
    char messages[20];

    serversocket = socket(AF_INET, SOCK_DGRAM, 0);

    bzero((char *)&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    printf("Enter the port : ");
    scanf("%d", &port);
    serveraddr.sin_port = htons(port);
    serveraddr.sin_addr.s_addr = INADDR_ANY;

    bind(serversocket, (struct sockaddr *)&serveraddr, sizeof(serveraddr));

    bzero((char *)&clientaddr, sizeof(clientaddr));
    len = sizeof(clientaddr);

    recvfrom(serversocket, &number, sizeof(number), 0, (struct sockaddr *)&clientaddr, &len);
    if (prime(number) == 1)
        sendto(serversocket, "Prime Number", sizeof("Prime Number"), 0, (struct sockaddr *)&clientaddr, sizeof(clientaddr));
    else
        sendto(serversocket, "Not Prime Number", sizeof("Not Prime Number"), 0, (struct sockaddr *)&clientaddr, sizeof(clientaddr));

    close(clientsocket);
    close(serversocket);
}