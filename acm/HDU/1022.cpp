#include <iostream>
#include <stack>

using namespace std;

const int MAXLEN = 100;
const int MAXN = 10;

int main()
{
	freopen("in.txt", "r", stdin);

	int n;
	char step[MAXLEN];
	char in[MAXN];
	char out[MAXN];
	stack<int> trains;

	while(scanf("%d%s%s", &n, in, out) != EOF)
	{
		int in_index = 0, out_index = 0, step_index = 0;
		memset(step, 0, sizeof(step));
		while(!trains.empty())
		{
			trains.pop();
		}
		while(in[in_index] != '\0' || out[out_index] != '\0')
		{
			if (trains.empty() || trains.top() != out[out_index])
			{
				if (in[in_index] == '\0') {
					break;
				}
				trains.push(in[in_index]);
				in_index++;
				strcpy(step+step_index, "in\n");
				step_index += 3;
			}
			else
			{
				trains.pop();
				out_index++;
				strcpy(step+step_index, "out\n");
				step_index += 4;
			}
		}
		if (out[out_index] == '\0') {
			printf("Yes.\n%sFINISH\n", step);
		}
		else
		{
			printf("No.\nFINISH\n");
		}
	}

	fclose(stdin);
	return 0;
}
