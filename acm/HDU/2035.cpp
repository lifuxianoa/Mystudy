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
	x %= 1000;
	if (x == 0)
	{
		return 0;
	}

	if (y >= 2)
	{
		if ((y % 2) == 1)
		{
			res *= x;
		}
		y /= 2;
		return (res * getNumber((x * x) % 1000, y)) % 1000;
	}
	else
	{
		return x % 1000;
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int a, b;

	while((scanf("%d%d", &a, &b) != EOF && !(a == 0 && b == 0)))
	{
		printf("%d\n", getNumber(a, b));
	}

	fclose(stdin);
	//fclose(stdout);
}
