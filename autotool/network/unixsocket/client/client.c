#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>
#include <string.h>
#include <errno.h>

#define SOCK_SUN_PATH "/tmp/buddy"

char *getresp(int fd);

int main(int argc, char *argv[])
{
    int sockfd;
    struct sockaddr_un addr;
    int i_ret = 0;
    char data[] = "DATASEND---------------------++";
    unsigned int data_len = strlen(data);

    bzero(&addr, sizeof(addr));
    addr.sun_family = AF_LOCAL;
    strncpy(addr.sun_path, SOCK_SUN_PATH, sizeof(addr.sun_path) - 1);
    printf("sun_path=%s\n", addr.sun_path);
    
    for(;;)
    {
        int n = 0;
        char *psz_resp = NULL;

        if ((sockfd = socket(AF_LOCAL, SOCK_STREAM, 0)) < 0)
        {
            perror("generate error");
            exit(1);
        }

        i_ret = connect(sockfd, (struct sockaddr *)&addr,
                sizeof(addr));
        if (-1 == i_ret)
        {
            perror("connect failed");
            return 1;
        }
        printf("connect i_ret=%d\n", i_ret);

        n = write(sockfd, &data_len, sizeof(data_len));
        printf("n1 = %d\n", n);

        n = write(sockfd, data, data_len);
        printf("n2 = %d\n", n);

        psz_resp = getresp(sockfd);

        if (NULL == psz_resp)
        {
            printf("get response failed!\n");
        }
        else
        {
            printf("psz_resp=%s\n", psz_resp);
        }
        close(sockfd);
        sleep(1);
    }

    return 0;
}

char *getresp(int fd)
{
    unsigned int cmd_len = 0;
    int n = 0;
    char *psz_data = NULL;

    n = read(fd, &cmd_len, sizeof(unsigned int));

    printf("n=%d, cmd_len=%u\n", n, cmd_len);
    if (0 >= cmd_len)
    {
        return NULL;
    }

    psz_data = (char *)malloc(cmd_len + 1);
    if (NULL == psz_data)
    {
        printf("malloc failed!\n");
        return NULL;
    }

    n = read(fd, psz_data, cmd_len);
    printf("n=%d, resp=%s\n", n, psz_data);

    return psz_data;
}

