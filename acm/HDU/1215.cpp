/*
 * 1000.cpp
 *
 *  Created on: 2013-8-26
 *      Author: Administrator
 */

#include <iostream>
#include <math.h>
#include <time.h>

using namespace std;

const int T = 500000;
const int N = 500000;
int ans[N + 1];

int fun(int n)
{
	if (ans[n] == 0)
	{
		int i;
		int t = (int) sqrt((double) n);

		ans[n] = 1;
		for (i = 2; i <= t; ++i)
		{
			if (n % i == 0)
			{
				ans[n] += i + n / i;
			}
		}
		if ((i - 1) * (i - 1) == n && i != 2)
		{
			ans[n] -= i - 1;
		}
	}

	return ans[n];
}

int main()
{
	freopen("in.txt", "r", stdin);

	int t, n;

	scanf("%d", &t);
	for (int i = 0; i < t; ++i)
	{
		scanf("%d", &n);
		printf("%d\n", fun(n));
	}

	fclose(stdin);
	return 0;
}
