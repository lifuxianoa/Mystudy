#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 50010;
int num[MAXN];

inline int binary_search(vector<int> &arr, int key)
{
	int low = 0, high = arr.size() - 1;

	//注意等号
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (arr[mid] < key)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}

	return low;
}

int max_road(int a[], int len)
{
	vector<int> arr;

	arr.clear();
	for (int i = 1; i <= len; ++i)
	{
		if (num[i] == 0)
		{
			continue;
		}

		if (arr.size() == 0)
		{
			arr.push_back(a[i]);
		}
		else
		{
			if (arr[arr.size() - 1] < a[i])
			{
				arr.push_back(a[i]);
			}
			else
			{
				int pos = binary_search(arr, a[i]);
				arr[pos] = a[i];
			}
		}
	}

	return arr.size();
}

int main()
{
	freopen("in.txt", "r", stdin);

	int n;
	int count = 1;
	while(scanf("%d", &n) != EOF)
	{
		int max = 0;
		int p, r;
		memset(num, 0, sizeof(num));
		for (int i = 0; i < n; ++i)
		{
			scanf("%d%d", &p, &r);
			num[p] = r;
			if (max < p)
			{
				max = p;
			}
		}

		printf("Case %d:\n", count++);
		int res = max_road(num, max);
		if (res <= 1)
		{
			printf("My king, at most %d road can be built.\n\n", res);
		}
		else
		{
			printf("My king, at most %d roads can be built.\n\n", res);
		}
	}

	fclose(stdin);
	return 0;
}
