#include <stdio.h>
#include<algorithm>

using namespace std;

const int MAXN = 1000;

struct Mouse
{
	int w;
	int s;
	int n;
}mouses[MAXN];

bool compare(const Mouse &a, const Mouse &b)
{
	if (a.w == b.w) {
		return a.s < b.s;
	} else {
		return a.w < b.w;
	}
}

int f[MAXN];
int p[MAXN];

void printLIS(int max_i)
{
	if (p[max_i] == max_i) {
		printf("%d\n", mouses[max_i].n);
		return;
	}

	printLIS(p[max_i]);
	printf("%d\n", mouses[max_i].n);
}

int main()
{
	freopen("in.txt", "r", stdin);

	int w, s, count = 0;
	int max = 0, max_i = 0;
	while(scanf("%d%d", &w, &s) != EOF)
	{
		mouses[count].w = w;
		mouses[count].s = s;
		mouses[count].n = count + 1;
		count++;
	}
	sort(mouses, mouses + count, compare);

	for (int i = 0; i < MAXN; ++i) {
		f[i] = 1;
		p[i] = i;
	}
	for (int i = 0; i < count; ++i) {
		for (int j = 0; j < i; ++j) {
			if (mouses[j].s > mouses[i].s && mouses[j].w < mouses[i].w) {
				if (f[i] < f[j] + 1) {
					f[i] = f[j] + 1;
					p[i] = j;
					if (f[i] > max) {
						max = f[i];
						max_i = i;
					}
				}
			}
		}
	}

	printf("%d\n", max);

	printLIS(max_i);
	fclose(stdin);
	return 0;
}
