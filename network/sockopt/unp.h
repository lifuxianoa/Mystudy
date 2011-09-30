#ifndef __UNP_H__
#define __UNP_H__

#include <stdio.h>
#include <stdlib.h>
#if 0
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h> //wait()
#include <sys/select.h> //select()
#include <sys/socket.h> //shutdown()

#endif

#define MAXLINE 1000
#define LISTENQ 1024
#define OPEN_MAX 1024

ssize_t readn(int fd, void *vptr, size_t n);

ssize_t writen(int fd, void *vptr, size_t n);

ssize_t readline(int fd, void *vptr, size_t maxlen);

void str_cli(FILE *fp, int sockfd);

void str_echo(int sockfd);

void sig_chld(int signo);

#endif
