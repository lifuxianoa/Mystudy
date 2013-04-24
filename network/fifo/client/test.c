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

void client(int readfd, int writefd);

int main(int argc, char *argv[])
{
    int readfd, writefd;

    printf("c1\n");
    writefd = open(FIFO1, O_WRONLY, 0);
    printf("c2\n");
    readfd = open(FIFO2, O_RDONLY, 0);
    printf("c3\n");

    client(readfd, writefd);

    close(readfd);
    close(writefd);

    unlink(FIFO1);
    unlink(FIFO2);

    return 0;
}

void client(int readfd, int writefd)
{
    size_t len;
    ssize_t n;
    char buff[MAXLINE];
    int iret;
    char *str = NULL;

    /* read pathname */
    printf("Please input pathname\n");
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

