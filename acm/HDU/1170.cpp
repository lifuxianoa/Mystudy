/*
 * 1000.cpp
 *
 *  Created on: 2013-8-26
 *      Author: Administrator
 */

#include <stdio.h>

int main()
{
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int n = 0;
	char op;
	int a, b;

	scanf("%d\n", &n);

	for (int i = 0; i < n; ++i)
	{
		scanf("%c %d %d\n", &op, &a, &b);
		switch (op) {
			case '+':
				printf("%d\n", a + b);
				break;

			case '-':
				printf("%d\n", a - b);
				break;

			case '*':
				printf("%d\n", a * b);
				break;

			case '/':
				if (a % b == 0) {
					printf("%d\n", a / b);
				}
				else
				{
					printf("%.2lf\n", (double)a / b);
				}
				break;

			default:
				break;
		}
	}

	fclose(stdin);
	//fclose(stdout);
}
