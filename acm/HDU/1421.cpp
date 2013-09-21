#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;

const int MAXN = 2050;
const int MAXK = MAXN / 2;
int a[MAXN];
int f[MAXK][MAXN];

inline int min(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	freopen("in.txt", "r", stdin);

	int n, k;
	while (scanf("%d%d", &n, &k) != EOF)
	{
		for (int i = 1; i <= n; ++i)
		{
			scanf("%d", a + i);
		}

		sort(a + 1, a + n + 1);
		memset(f, 0, sizeof(f));
		for (int i = 1; i <= k; ++i)
		{
			for (int j = 2 * i; j <= n; ++j)
			{
				f[i][j] = f[i - 1][j - 2]
						+ (a[j] - a[j - 1]) * (a[j] - a[j - 1]);
				if (j > 2 * i && f[i][j] > f[i][j - 1])
				{
					f[i][j] = f[i][j - 1];
				}
			}
		}
		printf("%d\n", f[k][n]);
	}

	fclose(stdin);
	return 0;
}
