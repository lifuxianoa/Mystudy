#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	int r = a % b;
	while (r != 0)
	{
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}

int lcm(int a, int b)
{
	return a / gcd(a, b) * b;
}

int main()
{
	freopen("in.txt", "r", stdin);

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		int m, res_lcm = 0;
		scanf("%d", &m);
		for (int j = 0; j < m; ++j)
		{
			int val;
			scanf("%d", &val);
			if (res_lcm == 0)
			{
				res_lcm = val;
			}
			else
			{
				res_lcm = lcm(res_lcm, val);
			}
		}
		printf("%d\n", res_lcm);
	}

	fclose(stdin);
	return 0;
}
