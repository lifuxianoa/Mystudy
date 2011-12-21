#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sendcmd.h"

int main(int argc, char *argv[])
{
    char send_buf[] = "123456abcdefg";
    char *psz_resp = NULL;

    psz_resp = sendcmd_and_getresp(send_buf, strlen(send_buf), 3);

    if (NULL != psz_resp)
    {
        printf("resp: %s\n", psz_resp);
    }
    else
    {
        printf("error!!!\n");
    }

    return 0;
}

