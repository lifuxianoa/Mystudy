#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>

#define SERV_PORT 9000
#define MAXLINE 1024

struct tag_msgtosend
{
    unsigned int ui_length;
    char data[0];
};

int main(int argc, char *argv[])
{
    int sockfd;
    struct sockaddr_in serveraddr, cliaddr;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    
    bzero(&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serveraddr.sin_port = htons(SERV_PORT);

    if (1 == bind(sockfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr)))
    {
        perror("bind error");
        exit(1);
    }

    for(;;)
    {
        int n = 0;
        unsigned int ui_len = 0;
        struct tag_msgtosend *msg = NULL;
        socklen_t len = sizeof(cliaddr);

        n = recvfrom(sockfd, &ui_len, sizeof(ui_len), MSG_PEEK, (struct sockaddr*)&cliaddr, &len);
        printf("recv length: %d\n", n);
        ui_len = ntohl(ui_len);

        printf("recv msg: %u!!!\n", ui_len);
        if (0 == ui_len)
        {
            printf("msg length = %u\n", ui_len);
            continue;
        }

        msg = (struct tag_msgtosend*)malloc(
                sizeof(struct tag_msgtosend) + ui_len);
        bzero(msg, sizeof(struct tag_msgtosend) + ui_len);
        n = recvfrom(sockfd, msg, ui_len + 4, 0, (struct sockaddr*)&cliaddr, &len);
        printf("recvfrom client: %s\n", msg->data);
        sendto(sockfd, msg, sizeof(struct tag_msgtosend) + ui_len,
                0, (struct sockaddr*)&cliaddr, len);
    }

    return 0;
}

