#include <iostream>

using namespace std;

const int MAXN = 1000000 + 1;

int sum[MAXN];
int num[MAXN];

int max(int a, int b)
{
	return a > b ? a : b;
}

int max_sum(int num[], int m, int n)
{
	for (int i = 1; i <= m; ++i)
	{
		int tmp = 0;
		for (int j = 1; j <= i; ++j)
		{
			tmp += num[j];
		}
		sum[n] = tmp;

		for (int j = i + 1; j <= n; ++j)
		{
			tmp = max(sum[j - 1], tmp) + num[j];
			sum[j - 1] = sum[n];
			sum[n] = max(tmp, sum[n]);
		}
	}

	return sum[n];
}

int main()
{
	freopen("in.txt", "r", stdin);

	int m, n;

	while(scanf("%d%d", &m, &n) != EOF)
	{
		memset(num, 0, sizeof(num));
		for (int i = 1; i <= n; ++i)
		{
			scanf("%d", num + i);
			sum[i] = 0;
		}
		printf("%d\n", max_sum(num, m, n));
	}

	fclose(stdin);
	return 0;
}
