#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <arpa/inet.h>

#define MAX_HOSTNAME_LEN 255
#define HOSTNAME_FILE "/etc/hostname"
#define ETH_NAME "eth0"

int get_hostname(char ptr_hostname[]);
int get_local_ip(char outip[]);

int main()
{
    char hostname[MAX_HOSTNAME_LEN] = {0};
    int i_ret;

    i_ret = get_hostname(hostname);
    printf("%s\n", hostname);

    memset(hostname, 0, MAX_HOSTNAME_LEN);
    i_ret = get_local_ip(hostname);
    printf("%s\n", hostname);

    return 0;
}

int get_hostname(char ptr_hostname[])
{
    FILE *file = fopen(HOSTNAME_FILE, "r");
    if (NULL == file)
    {
        printf("open file:%s failed\n", HOSTNAME_FILE);
        return 0;
    }
    size_t i_size = fread(ptr_hostname, 1, MAX_HOSTNAME_LEN, file);
    if (0 == i_size)
    {
        printf("read file:%s failed\n", HOSTNAME_FILE);
    }

    //去结尾的换行符
    char *ptr = strchr(ptr_hostname, '\r');
    if (NULL == ptr)
    {
        ptr = strchr(ptr_hostname, '\n');
    }

    if (NULL != ptr)
    {
        *ptr = '\0';
    }
    return strlen(ptr_hostname);
}

int get_local_ip(char outip[])
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
    sprintf(outip, "%s", inet_ntoa(sin.sin_addr));

    return strlen(outip);
}

