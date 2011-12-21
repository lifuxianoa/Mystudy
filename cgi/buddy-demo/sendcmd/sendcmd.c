#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

#include "sendcmd.h"

#define SERV_ADDR "127.0.0.1"
#define SERV_PORT 9000
#define MAXLINE 1024

struct tag_msgtosend
{
    unsigned int ui_length;
    char data[0];
};

/*
   说明：发送命令并等待应答
   参数：
    psz ---- 字符串指针，指向要发送的数据
    length ---- 要发送的数据长度
    timeout ---- 等待应答的超时时间，单位是秒，为0时表示禁止超时。
            如果超时没有应答，返回值为NULL
    
  返回值：成功时返回接收缓冲区指针，注意使用完后需要调用者自己调用free释放内存。
        否则会造成内存泄露。
        失败时，返回NULL
   */
char* sendcmd_and_getresp(const char *psz, int length, int timeout)
{
    int sockfd;
    struct sockaddr_in serveraddr;
    struct timeval tv_timeout;
    int n = 0;
    socklen_t len = 0;
    struct tag_msgtosend *msg = NULL;
    unsigned int ui_recv_len = 0;
    char *psz_recvbuff = NULL;

    if ((NULL == psz) || (0 == length))
    {
        fprintf(stderr, "invalid parameter!!!\n");
        return NULL;
    }
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    
    bzero(&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(SERV_PORT);
    if (inet_pton(AF_INET, SERV_ADDR, &serveraddr.sin_addr) <= 0)
    {
        fprintf(stderr, "[%s] is not a valid IP address\n", SERV_ADDR);
        return NULL;
    }

    tv_timeout.tv_sec = timeout;
    tv_timeout.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &tv_timeout,
            sizeof(tv_timeout));

    msg = (struct tag_msgtosend*)malloc(sizeof(struct tag_msgtosend) + length);
    bzero(msg, sizeof(struct tag_msgtosend) + length);
    msg->ui_length = htonl(length);
    strncpy(msg->data, psz, length);

    len = sizeof(serveraddr);
    n = sendto(sockfd, msg, sizeof(struct tag_msgtosend) + length, 0,
            (struct sockaddr*)&serveraddr, len);

    n = recvfrom(sockfd, &ui_recv_len, sizeof(ui_recv_len), 0, NULL, NULL);
    ui_recv_len = ntohl(ui_recv_len);
    printf("len: %u\n", ui_recv_len);
    if (0 == ui_recv_len)
    {
        fprintf(stderr, "recv response failed!\n");
        return NULL;
    }

    psz_recvbuff = (char *)malloc(ui_recv_len);
    bzero(psz_recvbuff, ui_recv_len);
    n = recvfrom(sockfd, psz_recvbuff, ui_recv_len, 0, NULL, NULL);
    printf("resp from server:%s\n", psz_recvbuff);
    
    return psz_recvbuff;
}

