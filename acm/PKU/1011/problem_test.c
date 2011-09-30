#include <glib.h>

static void cut(int length);
static void print_num(int num);

int main(int argc, char *argv[])
{
	cut(50);
	g_print("\n");
	print_num(50);
	return 0;
}

static void cut(int length)
{
	if(length > 5)
	{
		GRand * rand = g_rand_new();
		g_assert(rand);
		int rand_len = g_rand_int_range(rand, 1, length-1);
		g_rand_free(rand);
		rand = NULL;

		cut(rand_len);
		cut(length - rand_len);
	}
	else
	{
		g_print("%d ", length);
	}
}

static void print_num(int num)
{
	gint i;

	for(i=6; i<=num/2; i++)
	{
		if(num%i == 0)
		{
			g_print("%d ", i);
		}
	}
	g_print("\n");
}

