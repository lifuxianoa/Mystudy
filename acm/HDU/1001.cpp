#include <stdio.h>

using namespace std;

int main()
{
	freopen("in.txt", "r", stdin);

	unsigned int n;
	while (scanf("%u", &n) != EOF)
	{
		printf("%d\n\n", n * (n + 1) / 2);
	}

	fclose(stdin);
	return 0;
}
