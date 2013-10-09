#include <iostream>

using namespace std;

int main()
{
	freopen("in.txt", "r", stdin);

	const float PI = 3.1415927;
	int revolution, count = 0;
	float diameter, time, perimeter, distance, mph;
	while(scanf("%f%d%f", &diameter, &revolution, &time) != EOF && revolution != 0)
	{
		perimeter = diameter * PI;
		distance = perimeter * revolution;
		distance /= (12*5280);
		mph = distance * 3600 / time;
		printf("Trip #%d: %.2f %.2f\n", ++count, distance, mph);
	}

	fclose(stdin);
	return 0;
}
