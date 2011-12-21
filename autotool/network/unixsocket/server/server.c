#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>
#include <string.h>
#include <errno.h>

#define SOCK_SUN_PATH "/tmp/buddy"

int processcmd(int fd);

int main(int argc, char *argv[])
{
    int listenfd;
    struct sockaddr_un addr;
    int i_ret = 0;
    socklen_t addrlen = 0;

    listenfd = socket(AF_LOCAL, SOCK_STREAM, 0);

    unlink(SOCK_SUN_PATH);
    bzero(&addr, sizeof(addr));
    addr.sun_family = AF_LOCAL;
    strncpy(addr.sun_path, SOCK_SUN_PATH, sizeof(addr.sun_path) - 1);
    printf("sun_path=%s\n", addr.sun_path);
    i_ret = bind(listenfd, (struct sockaddr *)&addr, sizeof(addr));
    printf("i_ret=%d, listenfd=%d\n", i_ret, listenfd);

    i_ret = listen(listenfd, 1);
    printf("i_ret=%d\n", i_ret);

    for(;;)
    {
        int connfd;
        connfd = accept(listenfd, NULL, NULL);
        printf("accept\n");
        if (connfd < 0)
        {
            if (EINTR == errno)
            {
                continue;
            }
            else
            {
                perror("accept error");
                return 1;
            }
        }
        
        processcmd(connfd);
        close(connfd);
    }

    return 0;
}

int processcmd(int fd)
{
    unsigned int cmd_len = 0;
    int n = 0;
    char *psz_cmd = NULL;

    n = read(fd, &cmd_len, sizeof(unsigned int));

    printf("n=%d, cmd_len=%u\n", n, cmd_len);
    if (0 >= cmd_len)
    {
        return 1;
    }

    psz_cmd = (char *)malloc(cmd_len + 1);
    if (NULL == psz_cmd)
    {
        printf("malloc failed!\n");
        return 1;
    }

    n = read(fd, psz_cmd, cmd_len);
    printf("n=%d, cmd=%s\n", n, psz_cmd);

    //response
    n = write(fd, &cmd_len, sizeof(unsigned int));
    printf("response 1, n=%d\n", n);

    n = write(fd, psz_cmd, cmd_len);
    printf("response 2, n=%d\n", n);

    free(psz_cmd);
}

