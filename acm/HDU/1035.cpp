#include <iostream>

using namespace std;

const int MAXN = 12;
char map[MAXN][MAXN];
char flag[MAXN][MAXN];
int startcol;

void travel()
{
	memset(flag, 0, sizeof(flag));
	int row = 1, col = startcol;
	int step = 1;
	while (true)
	{
		flag[row][col] = step++;
		switch (map[row][col])
		{
		case 'N':
			row--;
			break;

		case 'S':
			row++;
			break;

		case 'W':
			col--;
			break;

		case 'E':
			col++;
			break;

		default:
			//get out of the grid
			printf("%d step(s) to exit\n", step - 2);
			return;
		}

		if (flag[row][col])
		{
			//find a loop
			printf("%d step(s) before a loop of %d step(s)\n",
					flag[row][col] - 1, step - flag[row][col]);
			break;
		}
	}
}

int main()
{
	freopen("in.txt", "r", stdin);

	int m, n, k;
	while(scanf("%d%d%d", &m, &n, &k) != EOF && (m || n || k))
	{
		memset(map, 0, sizeof(map));
		startcol = k;
		for (int i = 1; i <= m; ++i)
		{
			scanf("%s\n", &map[i][1]);
		}
		travel();
	}

	fclose(stdin);
	return 0;
}
