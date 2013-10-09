#include <iostream>
#include <vector>

using namespace std;

int main()
{
	freopen("in.txt", "r", stdin);

	int T, N;
	vector<int> arr;

	arr.reserve(1000);
	scanf("%d", &T);

	for (int i = 0; i < T; ++i) {
		scanf("%d", &N);
		for (int j = 0; j < N; ++j) {
			int n;
			scanf("%d", &n);
			arr.push_back(n);
		}
		sort(arr.begin(), arr.end());

		int len = arr.size();
		printf("%d", arr[0]);
		for (int j = 1; j < len; ++j) {
			printf(" %d", arr[j]);
		}
		printf("\n");
		arr.clear();
	}

	fclose(stdin);
	return 0;
}
