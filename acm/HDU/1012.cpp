#include <iostream>
#include<vector>

using namespace std;

const int MAXN = 10;
int n[MAXN];
double e[MAXN];

void init()
{
	n[0] = 1;
	e[0] = 1.0;
	for (int i = 1; i < MAXN; ++i)
	{
		n[i] = n[i - 1] * i;
		e[i] = e[i - 1] + (double) 1.0 / n[i];
	}
}

int main()
{
	freopen("in.txt", "r", stdin);

	init();
	printf("n e\n");
	printf("- -----------\n");
	for (int i = 0; i < MAXN; ++i)
	{
		if (i < 3)
		{
			printf("%d %.10g\n", i, e[i]);
		}
		else
		{
			printf("%d %.9f\n", i, e[i]);
		}
	}

	fclose(stdin);
	return 0;
}
