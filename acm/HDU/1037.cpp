#include <iostream>

using namespace std;

int main()
{
	freopen("in.txt", "r", stdin);

	const int CARH = 168;
	int height;
	while(scanf("%d", &height) != EOF)
	{
		if (height <= CARH)
		{
			printf("CRASH %d\n", height);
			return 0;
		}
	}

	printf("NO CRASH\n");
	fclose(stdin);
	return 0;
}
