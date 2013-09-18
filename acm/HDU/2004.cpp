#include <iostream>

using namespace std;

int main()
{
	freopen("in.txt", "r", stdin);

	int t;
	char score[] = {'E', 'D', 'C', 'B', 'A', 'A'};
	while(scanf("%d", &t) != EOF)
	{
		if (t < 0 || t > 100) {
			printf("Score is error!\n");
		} else {
			printf("%c\n", score[t >= 50 ? (t - 50) / 10 : 0]);
		}
	}

	fclose(stdin);
	return 0;
}
