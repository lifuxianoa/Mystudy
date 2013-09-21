#include <iostream>
#include <math.h>

using namespace std;

const int MAXN = 100000;

struct Point
{
	double x;
	double y;
} points[MAXN], points_y[MAXN];

bool comparex(const Point &a, const Point &b)
{
	return a.x < b.x;
}

bool comparey(const Point &a, const Point &b)
{
	return a.y < b.y;
}

inline double dis(const Point &a, const Point &b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double min_distance_y(int l, int r)
{
	if (r - l == 1)
	{
		return dis(points[l], points[r]);
	}

	int mid = (l + r) / 2;
	double ml = min_distance_y(l, mid);
	double mr = min_distance_y(mid, r);

	double min = ml > mr ? mr : ml;

	int mid_l = mid, mid_r = mid;
	while (mid_l >= l && points[mid_l].y > points[mid].y - min)
	{
		mid_l--;
	}
	mid_l++;
	while (mid_r <= r && points[mid_r].y < points[mid].y + min)
	{
		mid_r++;
	}
	mid_r--;

	if (mid_r - mid_l > 1)
	{
		memcpy(points_y, points + mid_l, mid_r - mid_l + 1);
		sort(points_y, points_y + mid_r - mid_l + 2, comparex);
		for (int i = mid_l; i < mid_r; ++i)
		{
			for (int j = i + 1; j < mid_r; ++j)
			{
				if (points[j].x - points[i].x < min)
				{
					double d = dis(points[i], points[j]);
					if (min > d)
					{
						min = d;
					}
				}
			}
		}
	}

	return min;
}

double min_distance_x(int l, int r)
{
	if (r - l == 1)
	{
		return dis(points[l], points[r]);
	}

	int mid = (l + r) / 2;
	double ml = min_distance_x(l, mid);
	double mr = min_distance_x(mid, r);

	double min = ml > mr ? mr : ml;

	int mid_l = mid, mid_r = mid;
	while (mid_l >= l && points[mid_l].x > points[mid].x - min)
	{
		mid_l--;
	}
	mid_l++;
	while (mid_r <= r && points[mid_r].x < points[mid].x + min)
	{
		mid_r++;
	}
	mid_r--;

	if (mid_r - mid_l > 1)
	{
		memcpy(points_y, points + mid_l, mid_r - mid_l + 1);
		sort(points_y, points_y + mid_r - mid_l + 2, comparey);
		for (int i = mid_l; i < mid_r; ++i)
		{
			for (int j = i + 1; j < mid_r; ++j)
			{
				if (points[j].y - points[i].y < min)
				{
					double d = dis(points[i], points[j]);
					if (min > d)
					{
						min = d;
					}
				}
			}
		}
	}

	return min;
}

int main()
{
	freopen("in.txt", "r", stdin);
	int n;

	while (scanf("%d", &n) != EOF && n != 0)
	{
		for (int i = 0; i < n; ++i)
		{
			scanf("%lf%lf", &(points[i].x), &(points[i].y));
		}

		sort(points, points + n, comparey);
		printf("%.2lf\n", min_distance_y(0, n - 1) / 2);
	}

	fclose(stdin);
	return 0;
}
