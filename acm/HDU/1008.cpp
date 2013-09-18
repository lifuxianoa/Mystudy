/*
 * 1000.cpp
 *
 *  Created on: 2013-8-26
 *      Author: Administrator
 */

#include <stdio.h>
#include <string.h>

void print(char *ptrIArray, int n)
{
	int sum = 0;
	int diff = ptrIArray[0];
	sum += diff * 6;
	for (int i = 0; i < n - 1; ++i) {
		diff = ptrIArray[i + 1] - ptrIArray[i];
		if (diff > 0) {
			sum += diff * 6;
		}
		else
		{
			sum += -diff * 4;
		}
	}
	sum += n * 5;
	printf("%d\n", sum);
}

int main()
{
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int n;
	char array[1000];

	while ((scanf("%d", &n) != EOF) && n != 0)
	{
		memset(array, 0, sizeof(array));
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", array + i);
		}
		print(array, n);
	}

	fclose(stdin);
	//fclose(stdout);
}
