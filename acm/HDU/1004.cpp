#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	freopen("in.txt", "r", stdin);

	int n;
	char color[16];
	map<string, int> result;
	map<string, int>::iterator iter, iter_max;
	string str_color;
	int max;

	while(scanf("%d", &n) != EOF && n !=0)
	{
		for (int i = 0; i < n; ++i) {
			scanf("%s", color);
			str_color = color;
			iter = result.find(str_color);
			if (iter == result.end()) {
				result.insert(pair<string, int>(str_color, 1));
			}
			else
			{
				iter->second++;
			}
		}

		max = 0;
		for (iter = result.begin();  iter != result.end(); ++iter) {
			if (max < iter->second) {
				max = iter->second;
				iter_max = iter;
			}
		}
		cout << iter_max->first << endl;
		result.clear();
	}

	fclose(stdin);
	return 0;
}
