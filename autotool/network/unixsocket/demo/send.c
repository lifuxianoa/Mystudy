/* ************************************************************************
 *       Filename:  send.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2011年12月03日 20时42分37秒
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
    int orig_sock, //客户端原来套接字描述符
        i; //循环计数器

    static struct sockaddr_un serv_adr;
    static char buf[10]; //消息缓冲区

    if((orig_sock = socket(AF_LOCAL,SOCK_STREAM,0)) < 0)
    {
        perror("generate error");
        exit(1);
    }

    serv_adr.sun_family = AF_LOCAL;
    strcpy(serv_adr.sun_path, NAME);

    if(connect(orig_sock, (struct sockaddr *)&serv_adr,
                sizeof(serv_adr)) < 0)
                //sizeof(serv_adr.sun_family) + strlen(serv_adr.sun_path)) < 0)
    {
        perror("connect error");
        exit(1);
    }

    for(i =1;i<=10;i++)
    {
        sprintf(buf,"c: %d\n\n",i);
        write(orig_sock,buf,sizeof(buf));
    }
    close(orig_sock);
    exit(0); 
}

