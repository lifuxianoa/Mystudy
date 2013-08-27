/*
 * 1000.cpp
 *
 *  Created on: 2013-8-26
 *      Author: Administrator
 */

#include <stdio.h>
#include <string.h>

bool prime[40];
int n;
int result[20];
bool flag[20];

void initPrime()
{
	memset(prime, true, sizeof(prime));
	prime[0] = false;
	prime[1] = false;

	for (int i = 2; i < 20; i++)
	{
		if (prime[i])
		{
			for (int j = 2; j <= 40 / i; ++j)
			{
				prime[i * j] = false;
			}
		}
	}
}

void print()
{
	for (int i = 1; i < n; ++i) {
		printf("%d ", result[i]);
	}
	printf("%d\n", result[n]);
}

void dfs(int step)
{
	if (step == n) {
		if (prime[result[n] + 1]) {
			print();
		}
	} else {
		for (int i = 2; i <= n; ++i) {
			if (!flag[i] && prime[result[step] + i]) {
				flag[i] = true;
				result[step + 1] = i;
				dfs(step + 1);
				flag[i] = false;
			}
		}
	}
}

int main()
{
	int count = 0;

	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	initPrime();
	while (scanf("%d", &n) != EOF)
	{
		printf("Case %d:\n", ++count);
		memset(flag, false, sizeof(flag));
		memset(result, 0, sizeof(result));
		flag[1] = true;
		result[1] = 1;
		dfs(1);
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
}
