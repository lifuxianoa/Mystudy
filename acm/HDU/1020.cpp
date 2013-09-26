#include <iostream>

using namespace std;

int main()
{
	freopen("in.txt", "r", stdin);

	int n;
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; ++i)
	{
		char c, last = '\0';
		int count = 0;
		while(scanf("%c", &c) != EOF)
		{
			if (c == '\n')
			{
				break;
			}
			if (c == last)
			{
				count++;
			}
			else
			{
				if (last != '\0')
				{
					if (count > 1)
					{
						printf("%d%c", count, last);
					}
					else
					{
						printf("%c", last);
					}
				}
				last = c;
				count = 1;
			}
		}

		if (count > 1)
		{
			printf("%d%c", count, last);
		}
		else
		{
			printf("%c", last);
		}

		printf("\n");
	}

	fclose(stdin);
	return 0;
}
