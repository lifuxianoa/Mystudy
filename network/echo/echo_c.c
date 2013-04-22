#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

//#include <sys/types.h>
#include <sys/socket.h> //socket AF_INET SOCK_STREAM
#include <netinet/in.h> //sockaddr_in
#include <arpa/inet.h> // inet_ntop()
#include <time.h>

#include "unp.h"

#define MAXCLI 5

int main(int argc, char *argv[])
{
    int i, clifd[MAXCLI];
    struct sockaddr_in servaddr;

    if(argc != 2)
    {
        printf("usage:echo_c <IP-address>\n");
        return -1;
    }

    bzero(&servaddr, sizeof(struct sockaddr_in));
    //strcpy(buff, "192.168.61.171");
    servaddr.sin_family = AF_INET;
    //inet_pton(AF_INET, buff, &servaddr.sin_addr);
    inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
    servaddr.sin_port = htons(1333);

    for(i=0; i<MAXCLI; i++)
    {
        clifd[i] = socket(AF_INET, SOCK_STREAM, 0);
        connect(clifd[i], (struct sockaddr*)&servaddr, sizeof(servaddr));
    }
    /*
       for(;;)
       {
       printf("Enter your input:\n");
       bzero(buff, 100);
       gets(buff);
       writen(clifd, buff, strlen(buff));
       readline(clifd, buff, 100);
       printf("recv from server: %s\n", buff);
       }
       */
    str_cli(stdin, clifd[0]);
    exit(0);
    //close(clifd);

    return 0;
}

