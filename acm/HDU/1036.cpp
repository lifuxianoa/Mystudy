#include <iostream>

using namespace std;

int main()
{
	freopen("in.txt", "r", stdin);

	int n, t;
	float distance;
	char time[8];
	int second;
	bool flag;

	scanf("%d%f", &n, &distance);

	while(scanf("%d", &t) != EOF)
	{
		second = 0;
		flag = false;
		for (int i = 0; i < n; ++i)
		{
			scanf("%s", time);
			if (flag)
			{
				continue;
			}

			if (time[0] == '-')
			{
				flag = true;
			}
			else
			{
				second += (time[0]-'0')*3600;
				second += ((time[2]-'0')*10 + (time[3]-'0'))*60;
				second += (time[5]-'0')*10 + time[6]-'0';
			}
		}

		int avg_time = (int)(second / distance + 0.5);
		if (flag)
		{
			printf("%3d: -\n", t);
		}
		else
		{
			printf("%3d: %d:%02d min/km\n", t, avg_time/60, avg_time%60);
		}
	}

	fclose(stdin);
	return 0;
}
