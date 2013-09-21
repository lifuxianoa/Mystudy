#include <stdio.h>
#include <string>

using namespace std;

const int MAXLEN = 1002;
char a[MAXLEN];
char b[MAXLEN];
char sum[MAXLEN];

int main()
{
	freopen("in.txt", "r", stdin);

	int n;
	char *pa, *pb, *psum;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(sum, 0, sizeof(sum));
		scanf("%s%s", a, b);

		if (i > 0) {
			printf("\n");
		}
		printf("Case %d:\n", i + 1);
		printf("%s + %s = ", a, b);

		pa = a + strlen(a) - 1;
		pb = b + strlen(b) - 1;
		psum = sum;
		while (pa >= a || pb >= b)
		{
			char ca = pa < a ? '0' : *pa--;
			char cb = pb < b ? '0' : *pb--;
			*psum++ = ca + cb - '0';
		}
		for (char *p = sum; p < psum; ++p)
		{
			if (*p > '9')
			{
				if (*(p + 1) == 0)
				{
					*(p + 1) += '1';
				}
				else
				{
					*(p + 1) += 1;
				}
				*p = (*p - '0') % 10 + '0';
			}
		}

		for (char *p = sum + strlen(sum) - 1; p >= sum; --p) {
			printf("%c", *p);
		}
		printf("\n");
	}

	fclose(stdin);
	return 0;
}
