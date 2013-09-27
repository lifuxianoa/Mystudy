#include <iostream>

using namespace std;

//母函数
int value[] =
{ 1, 2, 5 };
int num[3];

const int MAXN = 8010;
int a[MAXN];
int b[MAXN];

int min_val()
{
	memset(a, 0, sizeof(a));
	for (int i = 0; i <= num[0]; ++i)
	{
		a[i] = 1;
	}

	int max = num[0] * value[0] + num[1] * value[1] + num[2] * value[2];
	for (int i = 1; i < 3; ++i)
	{
		memset(b, 0, sizeof(b));
		for (int j = 0; j <= max; ++j)
		{
			if (a[j] == 0)
			{
				continue;
			}
			for (int k = 0; k <= num[i]; k++)
			{
				b[j + k * value[i]] += a[j];
			}
		}
		memcpy(a, b, sizeof(b));
	}

	int pos = 1;
	while (a[pos] != 0)
	{
		pos++;
	}

	return pos;
}

int main()
{
	freopen("in.txt", "r", stdin);

	int n1, n2, n5;
	while (scanf("%d%d%d", &n1, &n2, &n5) != EOF && (n1 || n2 || n5))
	{
		num[0] = n1;
		num[1] = n2;
		num[2] = n5;
		printf("%d\n", min_val());
	}

	fclose(stdin);
	return 0;
}
