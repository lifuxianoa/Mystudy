#include <iostream>
#include <math.h>

using namespace std;

const int MAXN = 12;
int a[MAXN];
bool flag[MAXN];
int target;
int res[5];

bool compare(const int &a, const int &b)
{
	return a > b;
}

bool dfs(int n)
{
	if (5 == n)
	{
		int sum = res[0] - res[1] * res[1] + res[2] * res[2] * res[2]
				- res[3] * res[3] * res[3] * res[3]
				+ res[4] * res[4] * res[4] * res[4] * res[4];
		if (sum == target)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	for (int i = 0; i < MAXN; ++i)
	{
		if (0 == a[i])
		{
			break;
		}
		if (flag[i])
		{
			continue;
		}

		flag[i] = true;
		res[n] = a[i];
		if (dfs(n + 1))
		{
			return true;
		}
		flag[i] = false;
	}
	return false;
}

int main()
{
	freopen("in.txt", "r", stdin);

	char letter[MAXN+1];

	while(scanf("%d", &target) != EOF)
	{
		scanf("%s", letter);
		if (0 == target && !strcmp(letter, "END"))
		{
			break;
		}

		memset(a, 0, sizeof(a));
		int i = 0;
		for (i = 0; i < MAXN; ++i)
		{
			if (!letter[i])
			{
				break;
			}
			a[i] = letter[i] - 'A' + 1;
		}
		sort(a, a+i, compare);
		memset(flag, false, sizeof(flag));
		if(!dfs(0))
		{
			printf("no solution\n");
		}
		else
		{
			for (i = 0; i < 5; ++i)
			{
				printf("%c", res[i]+'A' -1);
			}
			printf("\n");
		}
	}

	fclose(stdin);
	return 0;
}
