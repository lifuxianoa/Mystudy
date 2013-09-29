#include <iostream>
#include <stack>

using namespace std;

const int MAXM = 1000;
float sum[MAXM];
float sum1[MAXM];

int main()
{
	freopen("in.txt", "r", stdin);

	int n, m, k;
	while(scanf("%d%d%d", &n, &m, &k) != EOF)
	{
		memset(sum, 0, sizeof(sum));
		for (int i = 0; i < n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				float vote;
				scanf("%f", &vote);
				sum[j] += vote;
			}
		}
		memcpy(sum1, sum, (m+1)*sizeof(float));
		nth_element(sum1+1, sum1+m-k+1, sum1+m+1);

		float nth = sum1[m-k+1];
		stack<int> st;
		int count = 0;
		for (int i = 1; i <= m; ++i)
		{
			if (sum[i] >= nth)
			{
				st.push(i);
				if (++count == k)
				{
					break;
				}
			}
		}

		count = 0;
		while(!st.empty())
		{
			if (count == 0)
			{
				count++;
				printf("%d", st.top());
			}
			else
			{
				printf(" %d", st.top());
			}
			st.pop();
		}
		printf("\n");
	}

	fclose(stdin);
	return 0;
}
