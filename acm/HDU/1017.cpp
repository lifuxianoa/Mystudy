/*
 * 1000.cpp
 *
 *  Created on: 2013-8-26
 *      Author: Administrator
 */

#include <stdio.h>

int count(int n, int m)
{
	int sum = 0;
	for (int i = 1; i < n - 1; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if (0 == ((i * i + j * j + m) % (i * j)))
			{
				sum++;
			}
		}
	}
	return sum;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int num = 0;
	int n, m;

	scanf("%d", &num);

	for (int i = 0; i < num; ++i)
	{
		int sum = 0;
		while(scanf("%d %d", &n, &m) != EOF && n != 0)
		{
			printf("Case %d: %d\n", ++sum, count(n, m));
		}
		if (i != num - 1) {
			printf("\n");
		}
	}

	fclose(stdin);
	fclose(stdout);
}
