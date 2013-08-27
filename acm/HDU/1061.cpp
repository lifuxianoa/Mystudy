/*
 * 1000.cpp
 *
 *  Created on: 2013-8-26
 *      Author: Administrator
 */

#include <stdio.h>
#include <math.h>


int getNumber(unsigned int x, unsigned int y)
{
	int res = 1;
	x %= 10;
	if (y >= 2) {
		if ((y % 2) == 1) {
			res *= x;
		}
		y /= 2;
		return (res*getNumber(x * x, y))%10;
	}
	else
	{
		return (res * x) % 10;
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int n = 0;
	unsigned int digit = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &digit);
			printf("%d\n", getNumber(digit, digit));
	}

	fclose(stdin);
	//fclose(stdout);
}
