/*
 * 1000.cpp
 *
 *  Created on: 2013-8-26
 *      Author: Administrator
 */

#include <stdio.h>

bool isFlower(int n)
{
	int sum = 0;
	int digit = 0;
	int num = n;

	while(n > 0)
	{
		digit = n % 10;
		n /= 10;
		sum += digit * digit * digit;
	}
	if (sum == num)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int m, n;

	while(scanf("%d %d", &m, &n) != EOF)
	{
		bool flagHas = false;

		for (int i = m; i <= n; ++i) {
			if (isFlower(i)) {
				if (flagHas) {
					printf(" ");
				}
				flagHas = true;
				printf("%d", i);
			}
		}
		if (!flagHas) {
			printf("no");
		}
		printf("\n");
	}

	fclose(stdin);
	//fclose(stdout);
}
