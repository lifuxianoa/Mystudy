#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h> //wait()
#include <sys/select.h> //select()
#include <sys/socket.h> //shutdown()

#include "unp.h"

ssize_t readn(int fd, void *vptr, size_t n)
{
    ssize_t nleft;
    ssize_t nread;
    char *ptr;

    ptr = (char*)vptr;
    nleft = n;

    while(nleft > 0)
    {
        if((nread = read(fd, ptr, nleft)) < 0)
        {
            if(errno == EINTR)
            {
                nread = 0;
            }
            else 
            {
                return (-1);
            }
        }
        else if(nread == 0)
        {
            //EOF
            break;
        }

        nleft -= nread;
        ptr += nread;
    }

    return (n - nleft);
}

ssize_t writen(int fd, void *vptr, size_t n)
{
    ssize_t nleft;
    ssize_t nread;
    const char *ptr;

    ptr = (char*)vptr;
    nleft = n;

    while(nleft > 0)
    {
        if((nread = write(fd, ptr, nleft)) < 0)
        {
            if(errno == EINTR)
            {
                nread = 0;
            }
            else 
            {
                return (-1);
            }
        }
        else if(nread == 0)
        {
            //EOF
            break;
        }

        nleft -= nread;
        ptr += nread;
    }

    return (n - nleft);
}

ssize_t readline(int fd, void *vptr, size_t maxlen)
{
    ssize_t n, rc;
    char c, *ptr;

    ptr = (char*)vptr;

    for(n=1; n<maxlen; n++)
    {
        if( (rc = read(fd, &c, 1)) == 1)
        {
            *ptr++ = c;
            if(c == '\n')
            {
                break;
            }
        }
        else if(rc == 0)
        {
            if(n == 1)
            {
                return (0);
            }
            else
            {
                break;
            }
        }
        else
        {
            if(errno == EINTR)
            {
                n--;
                continue;
            }
            else
            {
                return (-1);
            }
        }
    }

    *ptr = 0;
    return (n);
}

void str_cli(FILE *fp, int sockfd)
{
    char sendline[MAXLINE], recvline[MAXLINE];
    
       while(fgets(sendline, MAXLINE, fp) != NULL)
       {
           writen(sockfd, sendline, strlen(sendline));

           if(readline(sockfd, recvline, MAXLINE) == 0)
           {
               printf("str_cli: server terminated prematurely\n");
           }
           fputs(recvline, stdout);
       }
          

/*
    fd_set readset;
    int maxfd, stdineof;

    stdineof = 0;
    for(;;)
    {
        FD_ZERO(&readset);
        maxfd = 0;

        if(stdineof == 0)
        {
            FD_SET(fileno(fp), &readset);
            maxfd = fileno(fp);
        }
        FD_SET(sockfd, &readset);

        maxfd = (maxfd > sockfd ? maxfd : sockfd) + 1;

        select(maxfd, &readset, NULL, NULL, NULL);

        if( FD_ISSET(sockfd, &readset) )
        {
            if(readline(sockfd, recvline, MAXLINE) == 0)
            {
                if(stdineof == 1)
                {
                    return;
                }
                else
                {
                    printf("str_cli: server terminated prematurely\n");
                    //return;
                }
            }
            fputs(recvline, stdout);
        }

        if( FD_ISSET(fileno(fp), &readset) )
        {
            if(fgets(sendline, MAXLINE, fp) == NULL)
            {
                stdineof = 1;
                shutdown(sockfd, SHUT_WR); //send FIN
                continue;
            }
            writen(sockfd, sendline, strlen(sendline));
        }
    }
*/
}

void str_echo(int sockfd)
{
    ssize_t n;
    char line[MAXLINE];

    for(;;)
    {
        if((n = readline(sockfd, line, MAXLINE)) == 0)
        {
            printf("connection closed by client!\n");
            return;
        }
        writen(sockfd, line, n);
    }
}

void sig_chld(int signo)
{
    pid_t pid;
    int stat;

    //pid = wait(&stat);
    while( (pid = waitpid(-1, &stat, WNOHANG)) > 0)
    {
        printf("child %d terminated!\n", pid);
    }

    return;
}
