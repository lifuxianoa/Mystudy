#include <iostream>

//经典母函数算法
using namespace std;

const int MAXV = 17;
const int MAXN = 305;
unsigned int a[MAXN];
unsigned int b[MAXN];

void init()
{
	for (int i = 0; i <= MAXN; ++i)
	{
		a[i] = 1;
	}
	for (int i = 2; i <= MAXV; ++i)
	{
		memset(b, 0, sizeof(b));
		for (int j = 0; j <= MAXN; ++j)
		{
			for (int k = 0; k <= MAXN - j; k += i*i)
			{
				b[j + k] += a[j];
			}
		}
		memcpy(a, b, sizeof(a));
	}
}

int main()
{
	freopen("in.txt", "r", stdin);

	init();
	int n = 0;
	while(scanf("%d", &n) != EOF && n != 0)
	{
		printf("%u\n", a[n]);
	}

	fclose(stdin);
	return 0;
}
