#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	unsigned long R;
	int X, Y;
	int x_val, y_val1, y_val2, y_val3;
	scanf("%x,%d,%d", &R, &X, &Y);
	//printf("%x,%d,%d\n", R, X, Y);
	
	x_val = ~(1<<X);
	y_val1 = (1<<Y);
	y_val2 = (1<<(Y-1));
	y_val3 = ~(1<<(Y-2));

	R = R & x_val;
	R = R | y_val1;
	R = R | y_val2;
	R = R & y_val3;
	//printf("x_val: %x\n", x_val);
	//printf("y_val1: %x\n", y_val1);
	//printf("y_val2: %x\n", y_val2);
	//printf("y_val3: %x\n", y_val3);
	printf("%x", R);
	return 0;
}

