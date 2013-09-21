#include <stdio.h>
#include <string>

using namespace std;

const int MAXN = 1000;
char x[MAXN], z[MAXN];
int f[MAXN][MAXN];

inline int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	freopen("in.txt", "r", stdin);

	int max_len = 0;
	int x_len, z_len;

	while (scanf("%s%s", x, z) != EOF)
	{
		max_len = 0;
		x_len = strlen(x);
		z_len = strlen(z);
		memset(f, 0, sizeof(f));

		for (int i = 1; i <= x_len; ++i)
		{
			for (int j = 1; j <= z_len; ++j)
			{
					if (x[i - 1] == z[j - 1])
					{
						f[i][j] = f[i - 1][j - 1] + 1;
					}
					else
					{
						f[i][j] = max(f[i - 1][j], f[i][j - 1]);
					}
				if (max_len < f[i][j])
				{
					max_len = f[i][j];
				}
			}
		}
		printf("%d\n", max_len);
	}

	fclose(stdin);
	return 0;
}
