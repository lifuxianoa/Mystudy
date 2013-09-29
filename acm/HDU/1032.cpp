#include <iostream>

using namespace std;

int getnum(int n)
{
	int count = 1;
	while (n != 1)
	{
		count++;
		if (n % 2)
		{
			n = 3 * n + 1;
		}
		else
		{
			n /= 2;
		}
	}
	return count;
}

int main()
{
	freopen("in.txt", "r", stdin);

	int n, m, l, r;
	while(scanf("%d%d", &n, &m) != EOF)
	{
		l = n > m ? m : n;
		r = n > m ? n : m;
		int max = 0;
		for (int i = l; i <=r; ++i)
		{
			int num = getnum(i);
			if (max < num)
			{
				max = num;
			}
		}
		printf("%d %d %d\n", n, m, max);
	}

	fclose(stdin);
	return 0;
}
