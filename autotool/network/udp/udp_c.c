#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>

#define SERV_PORT 9000
#define MAXLINE 1024

int main(int argc, char *argv[])
{
    int sockfd;
    char sz_sendmesg[MAXLINE] = {0};
    char sz_recvmesg[MAXLINE] = {0};
    struct sockaddr_in serveraddr;
    struct timeval tv_timeout;

    if (2 != argc)
    {
        printf("usage: udpc <IPAddress>\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    
    bzero(&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(SERV_PORT);
    if (inet_pton(AF_INET, argv[1], &serveraddr.sin_addr) <= 0)
    {
        printf("[%s] is not a valid IP address\n", argv[1]);
        exit(1);
    }

    tv_timeout.tv_sec = 3;
    tv_timeout.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &tv_timeout,
            sizeof(tv_timeout));
    strcpy(sz_sendmesg, "1111111111111111");
    for(;;)
    {
        int n = 0;
        socklen_t len = sizeof(serveraddr);

        n = sendto(sockfd, sz_sendmesg, strlen(sz_sendmesg), 0,
                (struct sockaddr*)&serveraddr, len);
        bzero(sz_recvmesg, MAXLINE);
        n = recvfrom(sockfd, sz_recvmesg, MAXLINE, 0, NULL, NULL);
        printf("resp from server:%s\n", sz_recvmesg);
        //sleep(1);
    }

    return 0;
}

