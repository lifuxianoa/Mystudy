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
#include <sys/socket.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    int socketfd[2];
    pid_t childpid;
    int ret;
    char c;

    ret = socketpair(AF_UNIX, SOCK_STREAM, 0, socketfd);
    if (0 != ret)
    {
        return -1;
    }

    if( (childpid = fork()) == 0 )
    {
        /* child */
        sleep(3);
        if( (ret = read(socketfd[0], &c, 1)) != 1 )
        {
            perror("read from socketfd[0] failed.\n");
        }
        printf("child read %c\n", c);
        ret = write(socketfd[0], "c", 1);
        exit(0);
    }

    /* parent */
    ret = write(socketfd[1], "p", 1);
    if( (ret = read(socketfd[1], &c, 1)) != 1 )
    {
        perror("read freom socketfd[1] failed.\n");
    }
    printf("parent read %c\n", c);
    waitpid(childpid, NULL, 0);
    exit(0);

    return 0;
}

