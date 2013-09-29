#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 110;
const int MAXM = 110;

char map[MAXN][MAXM];
bool flag[MAXN][MAXM];

struct Pos
{
	int x;
	int y;
	int t;
	Pos()
	{
	}

	Pos(int xx, int yy, int tt)
	{
		x = xx;
		y = yy;
		t = tt;
	}

	Pos(const Pos &p)
	{
		x = p.x;
		y = p.y;
		t = p.t;
	}

	const bool operator<(const Pos &p) const
	{
		return p.t < t;
	}
};

Pos p[MAXN][MAXM];

int direction[4][2] =
{
{ 1, 0 },
{ 0, 1 },
{ -1, 0 },
{ 0, -1 } };
int n, m;

int sum = 1;
void print_path(int x, int y)
{
	int px = p[x][y].x;
	int py = p[x][y].y;
	if (px == 1 && py == 1)
	{
		printf("%ds:(%d,%d)->(%d,%d)\n", sum++, px - 1, py - 1, x - 1, y - 1);
		return;
	}
	print_path(px, py);
	printf("%ds:(%d,%d)->(%d,%d)\n", sum++, px - 1, py - 1, x - 1, y - 1);
	if (map[x][y] >= '1' && map[x][y] <= '9')
	{
		int step = map[x][y] - '0';
		for (int i = 0; i < step; ++i)
		{
			printf("%ds:FIGHT AT (%d,%d)\n", sum++, x - 1, y - 1);
		}
	}
}

void bfs()
{
	priority_queue<Pos> list;
	list.push(Pos(1, 1, 0));
	p[1][1] = Pos(1, 1, 0);
	memset(flag, true, sizeof(flag));
	sum = 1;
	while (!list.empty())
	{
		Pos cur = list.top();
		list.pop();
		int x = cur.x;
		int y = cur.y;
		int t = cur.t;

		if (x == n && y == m)
		{
			printf(
					"It takes %d seconds to reach the target position, let me show you the way.\n",
					t);
			print_path(x, y);
			printf("FINISH\n");
			return;
		}

		for (int i = 0; i < 4; ++i)
		{
			int x_next = x + direction[i][0];
			int y_next = y + direction[i][1];
			if (flag[x_next][y_next] && map[x_next][y_next] != 'X')
			{
				flag[x_next][y_next] = false;

				int step = t + 1;
				if (map[x_next][y_next] >= '1' && map[x_next][y_next] <= '9')
				{
					step += map[x_next][y_next] - '0';
				}

				p[x_next][y_next] = Pos(x, y, step);
				list.push(Pos(x_next, y_next, step));
			}
		}
	}
	printf("God please help our poor hero.\nFINISH\n");
}

int main()
{
	freopen("in.txt", "r", stdin);

	while(scanf("%d%d", &n, &m) != EOF)
	{
		memset(map, 'X', sizeof(map));
		for (int i = 1; i <=n; ++i)
		{
			scanf("%s", &map[i][1]);
			map[i][m+1] = 'X';
		}
		bfs();
	}
	fclose(stdin);
	return 0;
}
