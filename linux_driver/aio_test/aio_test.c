/*
 * =============================================================================
 *
 *       Filename:  test.c
 *
 *    Description:  linux driver test
 *
 *        Version:  1.0
 *        Created:  2012年04月26日 16时21分41秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
//#include <fcntl.h>
//#include <sys/ioctl.h>
//#include <sys/stat.h>
#include <unistd.h>
//#include <signal.h>
#include <aio.h>
#include <string.h>
#include <errno.h>

#define BUFF_SIZE   1024
#define MAX_LIST    2
#define FILENAME    "/dev/globalfifo"
#define FILENAME1   "/dev/globalfifo1"

int main(int argc, char *argv[])
{
    int fd, fd1, ret;
    struct aiocb my_aiocb, my_aiocb1;
    struct aiocb *cblist[MAX_LIST];

    /* 清零aiocb结构体 */
    bzero((char *)&my_aiocb, sizeof(struct aiocb));
    bzero((char *)&my_aiocb1, sizeof(struct aiocb));
    memset(cblist, 0, sizeof(cblist));

    fd = open(FILENAME, O_RDONLY);
    if (fd < 0)
    {
        perror("open failed.");
    }

    /* 为aiocb请求分配数据缓冲区 */
    my_aiocb.aio_buf = malloc(BUFF_SIZE + 1);
    if (!my_aiocb.aio_buf)
    {
        perror("malloc failed.");
    }

    /* 初始化aiocb的成员 */
    my_aiocb.aio_fildes = fd;
    my_aiocb.aio_nbytes = BUFF_SIZE;
    my_aiocb.aio_offset = 0;
    my_aiocb.aio_lio_opcode = LIO_READ;

    fd1 = open(FILENAME1, O_RDONLY);
    if (fd1 < 0)
    {
        perror("open failed.");
    }

    /* 为aiocb请求分配数据缓冲区 */
    my_aiocb1.aio_buf = malloc(BUFF_SIZE + 1);
    if (!my_aiocb1.aio_buf)
    {
        perror("malloc failed.");
    }

    /* 初始化aiocb的成员 */
    my_aiocb1.aio_fildes = fd1;
    my_aiocb1.aio_nbytes = BUFF_SIZE;
    my_aiocb1.aio_offset = 0;
    my_aiocb1.aio_lio_opcode = LIO_READ;

    cblist[0] = &my_aiocb;
    cblist[1] = &my_aiocb1;

    /* 发起大量I/O操作 */
    ret = lio_listio(LIO_WAIT, cblist, MAX_LIST, NULL);

    if ((ret = aio_return(&my_aiocb)) > 0)
    {
        /* 获得异步读的返回值 */
        printf("111 aio_return, ret = %d, buff=%s\n", ret, 
                (char *)my_aiocb.aio_buf);
    }
    else
    {
        /* 读失败，分析errorno */
        perror("111 aio_return failed.");
    }

    if ((ret = aio_return(&my_aiocb1)) > 0)
    {
        /* 获得异步读的返回值 */
        printf("222 aio_return, ret = %d, buff=%s\n", ret, 
                (char *)my_aiocb1.aio_buf);
    }
    else
    {
        /* 读失败，分析errorno */
        perror("222 aio_return failed.");
    }

    free((void *)my_aiocb.aio_buf);
    free((void *)my_aiocb1.aio_buf);
    close(fd);
    close(fd1);

    return 0;
}

