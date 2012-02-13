#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>

#define SERV_PORT 7788
#define MAXLINE (1024 * 4)

char sz_sendmesg_temp[] = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
    "<xml>"
    "<cmd>get_diskinfo</cmd>"
    "<tag>9876543210</tag>"
    "<session>"
    "<name>name</name>"
    "<passwd>passwd</passwd>"
    "<salt>salt</salt>"
    "<logintime>logintime</logintime>"
    "<checkval>checkval</checkval>"
    "</session>"
    "<paramlist>"
    "<disk_name>/dev/sdb</disk_name>"
    "</paramlist>"
    "</xml>";

char sz_sendmesg_fixed[] = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
    "<xml>"
    "<cmd>get_sysinfo_fixed</cmd>"
    "<tag>1234567890</tag>"
    "<session>"
    "<name>name</name>"
    "<passwd>passwd</passwd>"
    "<salt>salt</salt>"
    "<logintime>logintime</logintime>"
    "<checkval>checkval</checkval>"
    "</session>"
    "</xml>";

int main(int argc, char *argv[])
{
    int sockfd;
    char sz_recvmesg[MAXLINE] = {0};
    struct sockaddr_in serveraddr;
    struct timeval tv_timeout;

    if (2 != argc)
    {
        printf("usage: udpc <IPAddress>\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    
    bzero(&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(SERV_PORT);
    if (inet_pton(AF_INET, argv[1], &serveraddr.sin_addr) <= 0)
    {
        printf("[%s] is not a valid IP address\n", argv[1]);
        exit(1);
    }

    tv_timeout.tv_sec = 3;
    tv_timeout.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &tv_timeout,
            sizeof(tv_timeout));
    for(;;)
    {
        int n = 0;
        socklen_t len = sizeof(serveraddr);

        n = sendto(sockfd, sz_sendmesg_temp, strlen(sz_sendmesg_temp), 0,
                (struct sockaddr*)&serveraddr, len);
        bzero(sz_recvmesg, MAXLINE);
        n = recvfrom(sockfd, sz_recvmesg, MAXLINE, 0, NULL, NULL);
        printf("resp from server:%s\n", sz_recvmesg);

        n = sendto(sockfd, sz_sendmesg_fixed, strlen(sz_sendmesg_fixed), 0,
                (struct sockaddr*)&serveraddr, len);
        bzero(sz_recvmesg, MAXLINE);
        n = recvfrom(sockfd, sz_recvmesg, MAXLINE, 0, NULL, NULL);
        printf("resp from server:%s\n", sz_recvmesg);

        //usleep(1000 * 1000);
        //usleep(1);
    }

    return 0;
}

