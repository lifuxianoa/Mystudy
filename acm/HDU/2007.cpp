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

	int m, n, x, y;
	while(scanf("%d%d", &m, &n) != EOF)
	{
		if (m > n) {
			int tmp = m;
			m = n;
			n = tmp;
		}
		x = y =0;
		for (int i = m; i <= n; ++i) {
			if (i % 2 == 0) {
				x += i * i;
			} else {
				y += i * i * i;
			}
		}
		printf("%d %d\n", x, y);
	}

	fclose(stdin);
	return 0;
}
