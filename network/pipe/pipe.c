/*
 * =====================================================================================
 *
 *       Filename:  pipe.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年04月22日 10时05分09秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#define MAXLINE 1024

void client(int readfd, int writefd);
void server(int readfd, int writefd);

int main(int argc, char *argv[])
{
    int pipe1[2], pipe2[2];
    pid_t childpid;
    int ret;

    ret = pipe(pipe1);
    if (0 != ret)
    {
        return 1;
    }
    ret = pipe(pipe2);
    if (0 != ret)
    {
        return 1;
    }

    if( (childpid = fork()) == 0 )
    {
        /* child */
        close(pipe1[1]);
        close(pipe2[0]);

        server(pipe1[0], pipe2[1]);
        exit(0);
    }

    /* parent */
    close(pipe1[0]);
    close(pipe2[1]);
    
    client(pipe2[0], pipe1[1]);
    waitpid(childpid, NULL, 0);
    exit(0);

    return 0;
}

void server(int readfd, int writefd)
{
    int fd;
    ssize_t n;
    char buff[MAXLINE];
    int iret;

    /* read path name */
    if( (n = read(readfd, buff, MAXLINE)) == 0 )
    {
        fprintf(stderr, "end-of-file while reading pathname");
    }
    buff[n] = '\0';

    if( (fd = open(buff, O_RDONLY)) < 0 )
    {
        /* error; must tell client */
        snprintf(buff + n, sizeof(buff) - n, ":can't open, %s\n",
                strerror(errno));
        n = strlen(buff);
        iret = write(writefd, buff, n);
        printf("write %d bytes to pipe\n", iret);
    }
    else
    {
        /* open succeeded: copy file to IPC channel */
        while( (n = read(fd, buff, MAXLINE)) > 0 )
        {
            iret = write(writefd, buff, n);
            printf("write %d bytes to pipe\n", iret);
        }
        close(fd);
    }
}

void client(int readfd, int writefd)
{
    size_t len;
    ssize_t n;
    char buff[MAXLINE];
    int iret;
    char *str = NULL;

    /* read pathname */
    str = fgets(buff, MAXLINE, stdin);
    printf("str = %s\n", str);
    len = strlen(buff);
    if( buff[len - 1] == '\n')
    {
        len--;   
    }

    /* write pathname to IPC channel */
    iret = write(writefd, buff, len);
    printf("write %d bytes\n", iret);

    /* read from IPC, write to standard output */
    while( (n = read(readfd, buff, MAXLINE)) > 0 )
    {
        iret = write(STDOUT_FILENO, buff, n);
        printf("write %d bytes to stdout\n", iret);
    }
}

