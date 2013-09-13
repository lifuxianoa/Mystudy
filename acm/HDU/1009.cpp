/*
 * 1000.cpp
 *
 *  Created on: 2013-8-26
 *      Author: Administrator
 */

#include <iostream>
#include <map>

using namespace std;

const int MAXLEN = 1000;

int J[MAXLEN], F[MAXLEN];
double R[MAXLEN];

double calc(int m, int n)
{
	double sum = 0.0f;
	multimap<double, int> Pri;

	if (0 == n)
	{
		return sum;
	}

	for (int i = 0; i < n; ++i) {
		Pri.insert(make_pair(R[i], i));
	}

	multimap<double, int>::iterator iter, iterTmp;
	iterTmp = Pri.begin();
	while (iterTmp != Pri.end())
	{
		iter = iterTmp;
		iterTmp++;
	}

	while(m > 0)
	{
		//printf("%f, %d\n", iter->first, iter->second);
		int index = iter->second;
		if (m > F[index]) {
			sum += J[index];
			m -= F[index];
		} else {
			sum += m * (double)J[index] / F[index];
			m = 0;
		}
		iter--;
	}
	Pri.clear();

	return sum;
}

int main()
{
	freopen("in.txt", "r", stdin);
	int M, N;
	double max = 0.0f;
	while(scanf("%d%d", &M, &N) != EOF &&
			(-1 != M && -1 != N))
	{
		for (int i = 0; i < N; ++i) {
			scanf("%d%d", J + i, F + i);
			R[i] = (double)J[i] / F[i];
		}

		max = calc(M, N);
		printf("%.03f\n", max);
	}

	fclose(stdin);
	return 0;
}
