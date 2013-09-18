/*
 * 1000.cpp
 *
 *  Created on: 2013-8-26
 *      Author: Administrator
 */

#include <stdio.h>
#include <string.h>

int lcm(int m, int n)
{
	int m_tmp = m;
	int n_tmp = n;
	while (m_tmp != n_tmp)
	{
		if (m_tmp > n_tmp) {
			n_tmp += n;
		}
		else
		{
			m_tmp += m;
		}
	}
	return m_tmp;
}

int main()
{
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int m, n;

	while (scanf("%d%d", &m, &n) != EOF)
	{
		printf("%d\n", lcm(m, n));
	}

	fclose(stdin);
	//fclose(stdout);
}
