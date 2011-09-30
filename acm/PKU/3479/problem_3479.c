#include <stdio.h>
//#include <stdlib.h>
#include <string.h>

static char decode_char(char c);
static void decode_str(char *str);

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

static char decode_char(char c)
{
	char ret = 0;

	if(c >= 65 && c <= 90)
	{
		ret = c - 5;
		if(ret < 65)
		{
			ret = ret + 26;
		}
	}
	return ret;
}

static void decode_str(char *str)
{
	while(*str)
	{
		if(*str >= 65 && *str <= 90)
		{
			*str = decode_char(*str);
		}
		str++;
	}
}

