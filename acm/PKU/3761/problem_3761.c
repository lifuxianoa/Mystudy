#include <stdio.h>
//#include <stdlib.h>
#include <string.h>

static int get_setps()
{
}
int main(int argc, char *argv[])
{
	char str_buf[200];

	bzero(str_buf, 200);
	while(1)
	{
		gets(str_buf);
		if(strcmp(str_buf, "START")==0)
		{

			decode_str(str_buf);
			printf("%s\n", str_buf);
		}
		else
		{
			break;
		}
		bzero(str_buf, 200);
		gets(str_buf);
	}
	return 0;
}

