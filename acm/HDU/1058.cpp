#include <iostream>
#include <time.h>

using namespace std;

const int MAXN = 5842;
int aRes[MAXN + 1];

void init()
{
	int t2 = 1, t3 = 1, t5 = 1, t7 = 1;
	int minT;
	aRes[1] = 1;
	for (int i = 2; i <= MAXN; ++i)
	{
		minT = 2 * aRes[t2];
		if (minT > 3 * aRes[t3])
		{
			minT = 3 * aRes[t3];
		}
		if (minT > 5 * aRes[t5])
		{
			minT = 5 * aRes[t5];
		}
		if (minT > 7 * aRes[t7])
		{
			minT = 7 * aRes[t7];
		}
		if (minT == 2 * aRes[t2])
		{
			t2++;
		}
		if (minT == 3 * aRes[t3])
		{
			t3++;
		}
		if (minT == 5 * aRes[t5])
		{
			t5++;
		}
		if (minT == 7 * aRes[t7])
		{
			t7++;
		}
		aRes[i] = minT;
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	init();

	int n;
	while(scanf("%d", &n) != EOF && n != 0)
	{
		if (n % 10 == 1 && n % 100 != 11)
		{
			printf("The %dst humble number is %d.\n", n, aRes[n]);
		}
		else if (n % 10 == 2 && n % 100 != 12)
		{
			printf("The %dnd humble number is %d.\n", n, aRes[n]);
		}
		else if (n % 10 == 3 && n % 100 != 13)
		{
			printf("The %drd humble number is %d.\n", n, aRes[n]);
		}
		else
		{
			printf("The %dth humble number is %d.\n", n, aRes[n]);
		}
	}
	fclose(stdin);
	return 0;
}
