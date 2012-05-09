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
#include <sys/stat.h>
#include <unistd.h>
#include <signal.h>

#define DEVICE_FILE "/dev/second"

int main(int argc, char *argv[])
{
    int fd;
    int counter = 0;
    int old_counter = 0;
    int ret = 0;

    /* 打开/dev/second设备文件 */
    fd = open(DEVICE_FILE, O_RDONLY);
    if (fd != -1)
    {
        while (1)
        {
            /* 读目前经历的秒数 */
            ret = read(fd, &counter, sizeof(unsigned int));
            if (counter != old_counter)
            {
                printf("seconds after open /dev/second :%d\n", counter);
                old_counter = counter;
            }
        }
    }
    else
    {
        printf("Device open failure\n");
    }

    return 0;
}

