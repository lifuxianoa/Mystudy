#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 101;

struct BigNumber
{
	vector<unsigned int> data;
};

BigNumber f[MAXN];

void big_print(BigNumber &a)
{
	for (int i = a.data.size() - 1; i >= 0; --i)
	{
		printf("%d", a.data[i]);
	}
}

void big_add(BigNumber &a, BigNumber &b, BigNumber &c)
{
	int t = 0;
	int len_a = a.data.size();
	int len_b = b.data.size();
	int len = len_a > len_b ? len_a : len_b;

	c.data.clear();
	for (int i = 0; i < len; ++i)
	{
		int val_a = i > len_a - 1 ? 0 : a.data[i];
		int val_b = i > len_b - 1 ? 0 : b.data[i];
		int sum = val_a + val_b + t;
		t = sum / 10;
		c.data.push_back(sum % 10);
	}
	if (t > 0)
	{
		c.data.push_back(t);
	}
}

void big_multi(BigNumber &a, BigNumber &b, BigNumber &c)
{
	unsigned int a_len = a.data.size();
	unsigned int b_len = b.data.size();

	c.data.clear();
	for (unsigned int i = 0; i < a_len; ++i)
	{
		int t = 0;
		for (unsigned int j = 0; j < b_len; ++j)
		{
			if ((i + j) < c.data.size())
			{
				c.data[i + j] += a.data[i] * b.data[j] + t;
				t = c.data[i + j] / 10;
				c.data[i + j] %= 10;
			}
			else
			{
				int val = a.data[i] * b.data[j] + t;
				t = val / 10;
				c.data.push_back(val % 10);
			}
		}
		if (t > 0)
		{
			if (c.data.size() < i + b_len + 1)
			{
				c.data.push_back(t);
			}
			else
			{
				c.data[i + b_len] += t;
			}
		}
	}
}

void init(void)
{
	f[0].data.push_back(1);
	f[1].data.push_back(1);
	for (int i = 2; i < MAXN; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			BigNumber num, num2;
			//f[i] += f[j] * f[i - j - 1];
			big_multi(f[j], f[i-j-1], num);
			big_add(f[i], num, num2);

			f[i].data.assign(num2.data.begin(), num2.data.end());
		}
	}
}

int main()
{
	freopen("in.txt", "r", stdin);

	init();

	int n;
	while(scanf("%d", &n) != EOF)
	{
		big_print(f[n]);
		printf("\n");
	}

	fclose(stdin);
	return 0;
}
