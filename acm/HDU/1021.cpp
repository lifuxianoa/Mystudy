/*
 * 1000.cpp
 *
 *  Created on: 2013-8-26
 *      Author: Administrator
 */

#include <iostream>

using namespace std;

int main()
{
	freopen("in.txt", "r", stdin);
	int n;

	while(scanf("%d", &n) != EOF)
	{
		if (((n - 2) % 4) == 0) {
			printf("yes\n");
		}
		else
		{
			printf("no\n");
		}
	}

	fclose(stdin);
}
