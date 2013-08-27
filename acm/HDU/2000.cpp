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
	char array[4];

	while(scanf("%s\n", array) != EOF)
	{
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3 - i - 1; ++j) {
				if (array[j] > array[j + 1]) {
					char tmp = array[j];
					array[j] = array[j + 1];
					array[j + 1] = tmp;
				}
			}
		}

		printf("%c %c %c\n", array[0], array[1], array[2]);
	}

	fclose(stdin);
	//fclose(stdout);
}
