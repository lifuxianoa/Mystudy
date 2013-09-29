#include <iostream.h>
#include <math.h>

//经典母函数算法
//using namespace std;

typedef unsigned long long ULL;

ULL getvalue(ULL row, ULL line)
{
	return (row - 1) * (row - 1) + line;
}

void getpos(ULL value, ULL &row, ULL &line)
{
	row = (ULL) ceil(sqrt(value));
	line = value - (row - 1) * (row - 1);
}

ULL distance(ULL from, ULL target)
{
	ULL row_s, line_s, row_d, line_d, step = 0, tmp;
	if (from > target)
	{
		tmp = from;
		from = target;
		target = tmp;
	}

	getpos(from, row_s, line_s);
	getpos(target, row_d, line_d);

	if (row_d == row_s)
	{
		return target - from;
	}
	else
	{
		step += 2 * (row_d - row_s) - 1;
		step += (line_s + 1) % 2;
		ULL min = getvalue(row_d, (line_s + 1) / 2 * 2);
		ULL tmp = row_s * row_s - from;
		tmp += (tmp + 1) % 2;
		ULL max = row_d * row_d - tmp;
		//printf("min=%llu, max=%llu\n", min, max);
		if (target >= min && target <= max)
		{
			step += line_d % 2;
		}
		else if (target < min)
		{
			step += min - target;
		}
		else
		{
			step += target - max;
		}
	}

	return step;
}

int distance1(int n, int m)
{
	int zx[2], yx[2];
	int min = n < m ? n : m;
	int max = n > m ? n : m;
	int a = (int) pow((double) min, 0.5);
	if (a * a < min)
		a++;
	zx[0] = (min - (a - 1) * (a - 1) - 1) / 2;
	yx[0] = (min - (a - 1) * (a - 1)) / 2;
	int b = (int) pow((double) max, 0.5);
	if (b * b < max)
		b++;
	zx[1] = (max - (b - 1) * (b - 1) - 1) / 2;
	yx[1] = (max - (b - 1) * (b - 1)) / 2;
	int aa =
			yx[0] + b - a - yx[1] > 0 ?
					yx[0] + b - a - yx[1] : yx[1] - (yx[0] + b - a);
	int bb = zx[1] > zx[0] ? zx[1] - zx[0] : zx[0] - zx[1];
	return aa + bb + b - a;
}

int main()
{
	freopen("in.txt", "r", stdin);

	ULL n, m;
	/*
	 while(scanf("%llu%llu", &n, &m) != EOF)
	 {
	 printf("%llu,%llu---->>%llu, %d\n", n, m, distance(n, m), distance1(n, m));
	 }
	 */
	for (ULL i = 1; i <= 10000; ++i)
	{
		for (ULL j = i; j <= 10000; ++j)
		{
			if (distance(i, j) != distance1(i, j))
			{
				printf("%llu,%llu---->>%llu, %d\n", i, j, distance(i, j),distance1(i, j));
			}
		}
	}
	fclose(stdin);
	return 0;
}
