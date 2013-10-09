#include <iostream>
#include <vector>

using namespace std;

void big_sum(vector<char> a, vector<char> b, vector<char> &c)
{
	char p = 0;
	int len_a = a.size();
	int len_b = b.size();

	int len = len_a > len_b ? len_a + 1 : len_b + 1;

	c.clear();
	c.reserve(len);

	for (int i = 0; i < len_a || i < len_b; ++i)
	{
		char value_a = 0, value_b = 0;
		char sum = 0;
		if (i < len_a)
		{
			value_a = a[i];
		}
		if (i < len_b)
		{
			value_b = b[i];
		}

		sum = value_a + value_b + p;
		c.push_back(sum % 10);
		p = sum / 10;
	}

	if (p > 0)
	{
		c.push_back(p);
	}
}

const int MAXN = 1001;
vector<char> res[MAXN];

void init()
{
	vector<char> tmp;
	res[1].push_back(0);
	res[2].push_back(1);
	res[3].push_back(1);
	for (int i = 4; i < MAXN; ++i) {
		big_sum(res[i-2], res[i-2], tmp);
		big_sum(res[i-1], tmp, res[i]);
	}
}

void print(vector<char> v)
{
	for (int i = v.size() - 1; i >= 0; --i)
	{
		printf("%d", v[i]);
	}
	printf("\n");
}

int main()
{
	freopen("in.txt", "r", stdin);

	init();

	int n;
	while(scanf("%d", &n) != EOF)
	{
		print(res[n]);
	}

	fclose(stdin);
	return 0;
}
