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
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#define FIFO1 "/tmp/fifo.1"
#define FIFO2 "/tmp/fifo.2"

#define MAXLINE 1024

void server(int readfd, int writefd);

int main(int argc, char *argv[])
{
    int readfd, writefd;

    unlink(FIFO1);
    unlink(FIFO2);
    if (0 != mkfifo(FIFO1, 0777) && (errno != EEXIST))
    {
        fprintf(stderr, "can't create %s", FIFO1);
        return -1;
    }
    if (0 != mkfifo(FIFO2, 0777) && (errno != EEXIST))
    {
        fprintf(stderr, "can't create %s", FIFO2);
        return -1;
    }

    printf("s1\n");
    readfd = open(FIFO1, O_RDONLY, 0);
    printf("s2\n");
    writefd = open(FIFO2, O_WRONLY, 0);
    printf("s3\n");
    server(readfd, writefd);
    close(readfd);
    close(writefd);

    unlink(FIFO1);
    unlink(FIFO2);

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
        close(fd);
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

