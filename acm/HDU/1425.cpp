/*
 * 1000.cpp
 *
 *  Created on: 2013-8-26
 *      Author: Administrator
 */

#include <iostream>
#include <bitset>

using namespace std;

const int MAX = 1000001;
const int MAX_NUM = 500000;
bitset<MAX> nums;

int main()
{
	freopen("in.txt", "r", stdin);
	int n, m, num;

	while(scanf("%d %d", &n, &m) != EOF)
	{
		bool has = false;
		int count = 0;
		nums.reset();
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &num);
			nums.set(num + MAX_NUM, 1);
		}

		for (int i = MAX - 1; i >= 0; i--)
		{
			if (nums[i] == 1) {
				count++;
				if (count > m) {
					break;
				}

				if(has)
				{
					printf(" %d", i - MAX_NUM);
				}
				else
				{
					printf("%d", i - MAX_NUM);
					has = true;
				}
			}
		}
		printf("\n");
	}

	fclose(stdin);
}
