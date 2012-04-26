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
#include <fcntl.h>
#include <sys/ioctl.h>

#define FIFO_CLEAR  0x1
#define DEVICE_FILE "/dev/globalfifo"

int main(int argc, char *argv[])
{
    int fd;
    fd_set rfds, wfds;  /* 读写文件描述符集 */

    /* 以非阻塞方式打开DEVICE_FILE 设备文件 */
    fd = open(DEVICE_FILE, O_RDONLY | O_NONBLOCK);
    if (-1 != fd)
    {
        /* FIFO清零 */
        if (ioctl(fd, FIFO_CLEAR, 0) < 0)
        {
            printf("ioctl command failed\n");
        }

        while(1)
        {
            FD_ZERO(&rfds);
            FD_ZERO(&wfds);
            FD_SET(fd, &rfds);
            FD_SET(fd, &wfds);

            select(fd + 1, &rfds, &wfds, NULL, NULL);

            /* 数据可获得 */
            if (FD_ISSET(fd, &rfds))
            {
                printf("Poll monitor: can be read\n");
            }

            /* 数据可写入 */
            if (FD_ISSET(fd, &wfds))
            {
                printf("Poll monitor: can be write\n");
            }
        }
    }
    else
    {
        printf("Device open failure\n");
    }
    return 0;
}

