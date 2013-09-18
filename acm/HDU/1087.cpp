#include <stdio.h>
#include<algorithm>

using namespace std;

const int MAXN = 1000;

int a[MAXN];
int f[MAXN];

int main()
{
	freopen("in.txt", "r", stdin);

	int max = 0;
	int n, value;

	while(scanf("%d", &n) != EOF && n != 0)
	{
		printf("xxxx%d\n", n);
		max = 0;
		memset(a, 0, sizeof(a));
		for (int i = 0; i < MAXN; ++i) {
			f[i] = 1;
		}

		for (int i = 0; i < n; ++i) {
			scanf("%d", &value);
			a[i] = value;
			for (int j = 0; j < i; ++j) {
				if (a[j] < value) {
					if (f[j] + value > f[i]) {
						f[i] = f[j] + value;
					}
				}
			}
			if (max < f[i]) {
				f[i] = max;
			}
		}
		printf("%d\n", max);
	}


	fclose(stdin);
	return 0;
}
