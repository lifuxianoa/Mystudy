#include <iostream>

using namespace std;

//母函数

const int MAXN = 51;
int val[MAXN];
int num[MAXN];

const int MAXSUM = 250005;
int a[MAXSUM];
int b[MAXSUM];
int n, sum;

void split()
{
	memset(a, 0, sizeof(a));
	for (int i = 0; i <= num[0]; ++i)
	{
		a[i * val[0]] = 1;
	}

	for (int i = 1; i < n; ++i)
	{
		memset(b, 0, sizeof(b));
		for (int j = 0; j <= sum; ++j)
		{
			if (a[j] == 0)
			{
				continue;
			}
			for (int k = 0; k <= num[i]; k++)
			{
				b[j + k * val[i]] += a[j];
			}
		}
		memcpy(a, b, sizeof(b));
	}

	//注意，要从中间网小的方向搜，因为sum/2要取整，可能比sum/2小
	for (int i = sum / 2; i >= 0; --i)
	{
		if (a[i] != 0)
		{
			printf("%d %d\n", sum-i, i);
			break;
		}
	}
}

int main()
{
	freopen("in.txt", "r", stdin);

	while (scanf("%d", &n) != EOF && n > 0)
	{
		sum = 0;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d%d", val + i, num + i);
			sum += val[i] * num[i];
		}
		split();
	}

	fclose(stdin);
	return 0;
}
