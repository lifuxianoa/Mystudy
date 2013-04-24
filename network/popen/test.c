/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年04月22日 10时05分09秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#define MAXLINE 1024

int main(int argc, char *argv[])
{
    size_t n;
    char buff[MAXLINE], command[MAXLINE];
    FILE *fp;
    char *str = NULL;

    /* read pathname */
    printf("Please input pathname to exec: ");
    str = fgets(buff, MAXLINE, stdin);
    printf("input pathname is: %s\n", str);
    n = strlen(buff);
    if (buff[n - 1] == '\n')
    {
        n--;
    }

    snprintf(command, sizeof(command), "%s", buff);
    fp = popen(command, "r");

    /* copy from pipe to standard output */
    while( fgets(buff, MAXLINE, fp) != NULL )
    {
        puts(buff);
    }
    pclose(fp);
    
    return 0;
}

