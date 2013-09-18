#include <stdio.h>
#include <time.h>
#include <vector>

using namespace std;

vector<unsigned __int64> res;

inline unsigned __int64 Min(unsigned __int64 a, unsigned __int64 b, unsigned __int64 c)
{
	unsigned __int64 m = a;
	if (m > b) {
		m = b;
	}
	if (m > c) {
		m = c;
	}
	return m;
}

unsigned __int64 fun(unsigned __int64 p1, unsigned __int64 p2, unsigned __int64 p3,
		unsigned __int64 n)
{
	unsigned __int64 t1 = 0, t2 = 0, t3 = 0;
	unsigned __int64 min;
	res.push_back(1);
	for (unsigned __int64 i = 1; i <= n; ++i)
	{
		unsigned __int64 m1 = p1 * res[t1];
		unsigned __int64 m2 = p2 * res[t2];
		unsigned __int64 m3 = p3 * res[t3];

		min = Min(m1, m2, m3);
		res.push_back(min);

		if (min == m1)
		{
			t1++;
		}
		if (min == m2)
		{
			t2++;
		}
		if (min == m3)
		{
			t3++;
		}
	}
	res.clear();
	return min;
}

int main()
{
	freopen("in.txt", "r", stdin);

	unsigned __int64 p1, p2, p3, n;
	while(scanf("%I64u%I64u%I64u%I64u", &p1, &p2, &p3, &n) != EOF)
	{
		printf("%I64u\n", fun(p1, p2, p3, n));
	}

	fclose(stdin);
	return 0;
}
