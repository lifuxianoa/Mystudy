#include <iostream>

using namespace std;
const int MAXLEN = 200;

int main()
{
	freopen("in.txt", "r", stdin);

	char str[MAXLEN];

	while(scanf("%s", str) != EOF)
	{
		int x = 310, y = 420, direction = 0;
		printf("300 420 moveto\n310 420 lineto\n");
		int len = strlen(str);
		for (int i = 0; i < len; ++i)
		{
			if (str[i] == 'A')
			{
				direction = (direction + 1) % 4;
			}
			else
			{
				direction = (direction - 1 + 4) % 4;
			}

			switch (direction)
			{
				case 0:
				x += 10;
				break;

				case 1:
				y -= 10;
				break;

				case 2:
				x -= 10;
				break;

				case 3:
				y += 10;
				break;

				default:
				break;
			}

			printf("%d %d lineto\n", x, y);
		}
		printf("stroke\nshowpage\n");
	}

	fclose(stdin);
	return 0;
}
