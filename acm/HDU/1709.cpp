#include <iostream>
#include <math.h>

using namespace std;

const int MAXS = 10005;
bool num[MAXS];
bool num1[MAXS];

int main()
{
	freopen("in.txt", "r", stdin);

	int n, w, sum;
	while (scanf("%d", &n) != EOF)
	{
		sum = 0;
		memset(num, false, sizeof(num));
		num[0] = true;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &w);
			sum += w;
			memcpy(num1, num, sizeof(num));
			for (int j = 0; j < MAXS; ++j)
			{
				if (num[j])
				{
					num1[abs(j - w)] = true;
					if (j + w < MAXS)
					{
						num1[j + w] = true;
					}
				}
			}
			memcpy(num, num1, sizeof(num1));
		}
		int count = 0;
		for (int j = 1; j < sum; ++j)
		{
			if (!num[j])
			{
				count++;
			}
		}
		printf("%d\n", count);
		if (count > 0) {
			count = 0;
			for (int j = 1; j < sum; ++j)
			{
				if (!num[j])
				{
					if (count == 0) {
						printf("%d", j);
						count = 1;
					}
					else
					{
						printf(" %d", j);
					}
				}
			}
			printf("\n");
		}
	}

	fclose(stdin);
	return 0;
}
