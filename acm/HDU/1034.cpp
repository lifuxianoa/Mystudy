#include <iostream>
#include <vector>

using namespace std;

int run(vector<int> &vec, int &final)
{
	int count = 0;
	int len = vec.size();
	bool flag = true;
	vector<int> tmp;
	tmp.resize(vec.size());
	while (flag)
	{
		count++;
		for (int i = 0; i < len; ++i)
		{
			int pre = (i - 1 + len) % len;
			tmp[i] = (vec[i] + vec[pre]) / 2;
		}
		memcpy(&vec[0], &tmp[0], len*sizeof(int));

		for (int i = 0; i < len; ++i)
		{
			vec[i] += vec[i] % 2;
		}

		flag = false;
		final = vec[0];
		for (int i = 1; i < len; ++i)
		{
			if (vec[i] != final)
			{
				flag = true;
				break;
			}
		}
	}
	return count;
}

int main()
{
	freopen("in.txt", "r", stdin);

	int n, num;
	vector<int> arr;
	int final;
	arr.reserve(1000);

	while(scanf("%d", &n) != EOF && n > 0)
	{
		arr.clear();
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &num);
			arr.push_back(num);
		}
		int time = run(arr, final);
		printf("%d %d\n", time, final);
	}

	fclose(stdin);
	return 0;
}
