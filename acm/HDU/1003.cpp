#include <stdio.h>
#include <string>

using namespace std;

int main()
{
	freopen("in.txt", "r", stdin);

	int t, n, max, sum, begin, end, begin1;
	scanf("%d", &t);

	for (int i = 0; i < t; ++i)
	{
		scanf("%d", &n);
		int tmp = 0;
		begin1 = begin = end = 1;

		for (int j = 1; j <= n; ++j) {
			scanf("%d", &tmp);
			if (j == 1) {
				sum = max = tmp;
				end = j;
			}
			else
			{
				sum += tmp;
			}
			if (max < sum) {
				max = sum;
				end = j;
				begin = begin1;
			}
			if (sum < 0) {
				sum = 0;
				begin1 = j + 1;
			}
		}

		if (i > 0) {
			printf("\n");
		}

		printf("Case %d:\n", i + 1);
		printf("%d %d %d\n", max, begin, end);
	}

	fclose(stdin);
	return 0;
}
