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
void server(int readfd, int writefd);

int main(int argc, char *argv[])
{
    int readfd, writefd;
    pid_t childpid;

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

    if( (childpid = fork()) == 0 )
    {
        /* child */
        printf("c1\n");
        readfd = open(FIFO1, O_RDONLY, 0);
        printf("c2\n");
        writefd = open(FIFO2, O_WRONLY, 0);
        printf("c3\n");
        server(readfd, writefd);
        close(readfd);
        close(writefd);
        exit(0);
    }

    /* When opening a FIFO with O_RDONLY or O_WRONLY set:
     * If O_NONBLOCK is set, an open() for reading-only shall return without delay. An open() for writing-only shall return an error if no process  currently  has
     * the file open for reading.
     * If  O_NONBLOCK  is  clear,  an open() for reading-only shall block the calling thread until a thread opens the file for writing.An open() for writing-only
     * shall block the calling thread until a thread opens the file for reading.
     * 因此，父进程和子进程中打开FIFO时，以只读、只写方式打开FIFO的顺序必须一致，比如都是先打开FIFO1，否则会造成死锁的发生！！！！！！！！！！！！！
     * */
    /* parent */
    printf("1\n");
    writefd = open(FIFO1, O_WRONLY, 0);
    printf("2\n");
    readfd = open(FIFO2, O_RDONLY, 0);
    printf("3\n");

    client(readfd, writefd);
    waitpid(childpid, NULL, 0);

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

