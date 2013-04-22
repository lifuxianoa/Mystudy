#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

//#include <sys/types.h>
#include <sys/socket.h> //socket AF_INET SOCK_STREAM
#include <netinet/in.h> //sockaddr_in
#include <arpa/inet.h> // inet_ntop()
#include <time.h>
#include <signal.h>
#include <errno.h>

#include "unp.h"

int main(void)
{
    int listenfd, connfd;
    struct sockaddr_in cliaddr, servaddr;
    char buff[100];
    socklen_t len;
    pid_t childpid;

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&servaddr, sizeof(struct sockaddr_in));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(1333);

    bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
    listen(listenfd, 10);

    signal(SIGCHLD, sig_chld);

    for(;;)
    {
        len = sizeof(cliaddr);
        connfd = accept(listenfd, (struct sockaddr*)&cliaddr, &len);

        if(connfd < 0)
        {
            if(errno == EINTR)
            {
                continue;
            }
            else
            {
                printf("accept error!\n");
            }
        }

        printf("connection from %s, port %d\n", inet_ntop(AF_INET, &cliaddr.sin_addr, buff, sizeof(buff)), ntohs(cliaddr.sin_port));

        if((childpid = fork()) == 0)
        {
            // child process
            close(listenfd);
            str_echo(connfd);
            exit(0);
        }
        close(connfd);
    }

    return 0;
}

