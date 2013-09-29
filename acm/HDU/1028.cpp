#include <iostream>

//经典母函数算法
using namespace std;

const int MAXN = 130;
unsigned int a[MAXN];
unsigned int b[MAXN];

int main()
{
	freopen("in.txt", "r", stdin);

	int n = 0;
	while(scanf("%d", &n) != EOF)
	{
		for (int i = 0; i <= n; ++i)
		{
			a[i] = 1;
		}
		for (int i = 2; i <= n; ++i)
		{
			memset(b, 0, sizeof(b));
			for (int j = 0; j <= n; ++j)
			{
				for (int k = 0; k <= n-j; k += i)
				{
					b[j+k] += a[j];
				}
			}
			memcpy(a, b, sizeof(a));
		}
		printf("%u\n", a[n]);
	}

	fclose(stdin);
	return 0;
}
