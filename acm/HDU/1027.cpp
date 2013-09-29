#include <iostream>

using namespace std;

const int MAXN = 1001;
int a[MAXN];
int main()
{
	freopen("in.txt", "r", stdin);

	int n, m;
	while(scanf("%d%d", &n, &m) != EOF)
	{
		for (int i = 0; i <= n; ++i)
		{
			a[i] = i;
		}
		for (int i = 0; i < m - 1; ++i)
		{
			next_permutation(a+1, a+n+1); //STL全排列函数
		}
		for (int j = 1; j < n; ++j)
		{
			printf("%d ", a[j]);
		}
		printf("%d\n", a[n]);
	}

	fclose(stdin);
	return 0;
}
