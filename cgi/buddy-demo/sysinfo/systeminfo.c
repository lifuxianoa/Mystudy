#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <arpa/inet.h>

#include "systeminfo.h"

#define MAX_HOSTNAME_LEN    255
#define MAX_IPADDR_LEN      64
#define HOSTNAME_FILE "/etc/hostname"
#define ETH_NAME "eth0"

static char gstr_hostname[MAX_HOSTNAME_LEN];
static char gstr_ipaddr[MAX_IPADDR_LEN];

char* get_hostname(void)
{
    FILE *file = fopen(HOSTNAME_FILE, "r");
    if (NULL == file)
    {
        printf("open file:%s failed\n", HOSTNAME_FILE);
        return NULL;
    }
    size_t i_size = fread(gstr_hostname, 1, MAX_HOSTNAME_LEN, file);
    if (0 == i_size)
    {
        printf("read file:%s failed\n", HOSTNAME_FILE);
    }

    //去结尾的换行符
    char *ptr = strchr(gstr_hostname, '\r');
    if (NULL == ptr)
    {
        ptr = strchr(gstr_hostname, '\n');
    }

    if (NULL != ptr)
    {
        *ptr = '\0';
    }
    return gstr_hostname;
}

char* get_local_ip(void)
{
    int sockfd;
    struct sockaddr_in sin;
    struct ifreq ifr;
    int i_ret;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0)
    {
        return 0;
    }

    strncpy(ifr.ifr_name, ETH_NAME, IFNAMSIZ);
    i_ret = ioctl(sockfd, SIOCGIFADDR, &ifr); //获取eth0接口信息
    if (-1 == i_ret)
    {
        return 0;
    }
    memcpy(&sin, &ifr.ifr_addr, sizeof(sin));
    sprintf(gstr_ipaddr, "%s", inet_ntoa(sin.sin_addr));

    return gstr_ipaddr;
}

