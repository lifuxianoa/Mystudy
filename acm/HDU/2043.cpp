/*
 * 1000.cpp
 *
 *  Created on: 2013-8-26
 *      Author: Administrator
 */

#include <stdio.h>
#include <string.h>

int divide(char c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return 1;
	}
	else if (c >= 'a' && c <= 'z')
	{
		return 2;
	}
	else if (c >= '0' && c <= '9')
	{
		return 3;
	}
	else if (c == '~' || c == '!' || c == '@' || c == '#' || c == '$'
			|| c == '%' || c == '^')
	{
		return 4;
	}

	return 0;
}

void print(char *str)
{
	char flag[5] =
	{ 0 };
	int len = strlen(str);
	if (len >= 8 && len <= 16)
	{
		for (int i = 0; i < len; ++i)
		{
			flag[divide(str[i])] = 1;
		}

		if ((flag[1] + flag[2] + flag[3] + flag[4]) >= 3)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	else
	{
		printf("NO\n");
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int n;
	char code[52];

	scanf("%d\n", &n);
	for (int i = 0; i < n; ++i)
	{
		memset(code, 0, sizeof(code));
		scanf("%s\n", code);
		print(code);
	}

	fclose(stdin);
	//fclose(stdout);
}
