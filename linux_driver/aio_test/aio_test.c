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

#define MAX_LIST    2
#define BUFF_SIZE   1024
#define FILENAME    "/dev/globalfifo"

void aio_completion_handler(int signo, siginfo_t *info, void *context)
{
    struct aiocb *req;

    /* 确定是我们需要的信号 */
    if (SIGIO == info->si_signo)
    {
        req = (struct aiocb *)info->si_value.sival_ptr; /* 获得aiocb */

        /* 请求的操作完成了吗？ */
        if (0 == aio_error(req))
        {
            /* 请求的操作完成，获取返回值 */
            if (aio_return(req) > 0)
            {
                /* 获得异步读的返回值 */
                printf("aio_return, buff=%s\n", (char *)req->aio_buf);
            }
            else
            {
                /* 读失败，分析errorno */
                perror("aio_return failed.");
            }

        }
    }
}

int main(int argc, char *argv[])
{
    int fd, ret;
    struct aiocb my_aiocb;
    struct sigaction sig_act;
    struct aiocb * cblist[MAX_LIST];

    fd = open(FILENAME, O_RDONLY);
    if (fd < 0)
    {
        perror("open failed.");
    }

    /* 清零aiocb结构体 */
    memset(cblist, 0, sizeof(cblist));
    bzero((char *)&my_aiocb, sizeof(struct aiocb));

    /* 为aiocb请求分配数据缓冲区 */
    my_aiocb.aio_buf = malloc(BUFF_SIZE + 1);
    if (!my_aiocb.aio_buf)
    {
        perror("malloc failed.");
    }
    memset((void *)my_aiocb.aio_buf, 0, BUFF_SIZE + 1);

    /* 设置信号处理函数 */
    sigemptyset(&sig_act.sa_mask);
    sig_act.sa_flags = SA_SIGINFO;
    sig_act.sa_sigaction = aio_completion_handler;

    /* 初始化aiocb的成员 */
    my_aiocb.aio_fildes = fd;
    my_aiocb.aio_nbytes = BUFF_SIZE;
    my_aiocb.aio_offset = 0;
    my_aiocb.aio_sigevent.sigev_notify = SIGEV_SIGNAL;
    my_aiocb.aio_sigevent.sigev_signo = SIGIO;
    my_aiocb.aio_sigevent.sigev_value.sival_ptr = &my_aiocb;

    cblist[0] = &my_aiocb;

    /* 将信号月信号处理函数绑定 */
    ret = sigaction(SIGIO, &sig_act, NULL);

    ret = aio_read(&my_aiocb);  /* 发出异步读请求 */
    ret = aio_suspend(cblist, MAX_LIST, NULL);

    free((void *)my_aiocb.aio_buf);
    close(fd);

    return 0;
}

