#include <iostream>
#include <map>

using namespace std;

int main()
{
	freopen("in.txt", "r", stdin);
	map<int, int> count;
	map<int, int>::iterator iter;

	int n, w;
	while (scanf("%d", &n) != EOF)
	{
		count.clear();
		for (int i = 0; i < n; ++i) {
			scanf("%d", &w);
			iter = count.find(w);
			if (iter != count.end()) {
				iter->second++;
			}
			else
			{
				count.insert(make_pair(w, 1));
			}
		}

		int max = (n+1)/2;
		for (iter = count.begin(); iter != count.end(); ++iter) {
			if (iter->second >= max) {
				printf("%d\n", iter->first);
				break;
			}
		}
	}

	fclose(stdin);
	return 0;
}
