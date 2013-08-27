/*
 * 1000.cpp
 *
 *  Created on: 2013-8-26
 *      Author: Administrator
 */

#include <stdio.h>
#include <string.h>

int digitalRoot(int a)
{
	int sum = 0;
	while(a > 0)
	{
		sum += a%10;
		a /= 10;
	}
	if(sum < 10)
	{
		return sum;
	}
	else
	{
		return digitalRoot(sum);
	}
}

int main() {
	int sum = 0;
	char str[1010];

	freopen("in.txt", "r", stdin);	//输入重定向，输入数据将从in.txt文件中读出
	freopen("out.txt", "w", stdout);	//输出重定向，输出数据将保存在out.txt文件中
	while (scanf("%s", str) != EOF && ('0' != str[0])) {
		sum = 0;
		int len = strlen(str);
		for (int i = 0; i < len; i++) {
			sum += str[i] - '0';
		}
		//printf("%d\n", sum%9 == 0 ? 9 : sum%9);
		printf("%d\n", digitalRoot(sum));
	}
	fclose(stdin);
	fclose(stdout);
}
