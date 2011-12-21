/* ************************************************************************
 *       Filename:  recv.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2011年12月03日 20时52分08秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  YOUR NAME (), 
 *        Company:  
 * ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>

#define NAME "/tmp/buddy"

int main()
{

    int orig_sock, //服务器端原来套接字描述符

        new_sock, //新的套接字描述符

        clnt_len, //客户端地址长度

        i; //循环计数器


    static struct sockaddr_un clnt_adr, //客户-服务器的UNIX地址

                              serv_adr;

    static char buf[128]; //消息缓冲区

    if((orig_sock = socket(AF_LOCAL,SOCK_STREAM,0)) < 0)
    {
        perror("generate error");
        exit(1);
    }
    serv_adr.sun_family = AF_LOCAL;
    strcpy(serv_adr.sun_path,NAME);
    unlink(NAME);
    if(bind(orig_sock, (struct sockaddr *)&serv_adr,
                sizeof(serv_adr)) < 0)
                //sizeof(serv_adr.sun_family) + strlen(serv_adr.sun_path)) < 0)
    {
        perror("bind error");
        close(orig_sock);
        unlink(NAME);
        exit(2);
    }
    listen(orig_sock,1);
    clnt_len = sizeof(clnt_adr);
    if((new_sock = accept (orig_sock, NULL, NULL))<0)
    //if((new_sock = accept (orig_sock,(struct sockaddr *)&clnt_adr,&clnt_len))<0)
    {
        perror("accept error");
        exit (3);
    }
    for(i =1;i<=10;i++)
    {
        sleep(1);
        read(new_sock,buf,sizeof(buf));
        printf("%s\n\n",buf);
    }
    close(new_sock);
    close(orig_sock);
    unlink(NAME);
 
    return 0;
}

