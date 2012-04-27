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
//#include <unistd.h>
//#include <signal.h>
#include <aio.h>
#include <string.h>
#include <errno.h>

#define BUFF_SIZE   1024
#define MAX_LIST    2
#define FILENAME    "/dev/globalfifo"

int main(int argc, char *argv[])
{
    int fd, ret;
    struct aiocb my_aiocb;
    struct aioct *cblist[MAX_LIST];

    fd = open(FILENAME, O_RDONLY);
    if (fd < 0)
    {
        perror("open failed.");
    }

    /* 清零aiocb结构体 */
    bzero((char *)&my_aiocb, sizeof(struct aiocb));
    memset(cblist, 0, sizeof(cblist));

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

    cblist[0] = &my_aiocb;

    ret = aio_read(&my_aiocb);
    if (ret < 0)
    {
        perror("aio_read failed.");
    }

#if 0
    while (EINPROGRESS == aio_error(&my_aiocb))
    {
        ;
    }
#endif

    ret = aio_suspend(cblist, MAX_LIST, NULL);

    if ((ret = aio_return(&my_aiocb)) > 0)
    {
        /* 获得异步读的返回值 */
        printf("aio_return, ret = %d, buff=%s\n", ret, 
                (char *)my_aiocb.aio_buf);
    }
    else
    {
        /* 读失败，分析errorno */
        perror("aio_return failed.");
    }

    return 0;
}

