#include <glib.h>

static void cut(int length, int num);
static void print_num(int num);
static gboolean isok(int *numbers, int size, int length);

#define MAX_LENGTH 5
static int nums[MAX_LENGTH+1];

int main(int argc, char *argv[])
{
#if 1
	int length, num;

	length = 10;
	num = 5;

	cut(length, num);
	g_print("\n");
	print_num(length*num);
#else
	nums[1] = 3;
	nums[2] = 3;
	nums[5] = 3;

	print_num(24);
#endif
	return 0;
}

static void cut(int length, int num)
{
	int i;
	for(i=0; i<num; i++)
	{
		if(num!=1)
		{
			g_print("\n----cut %d:>", i);
		}
		if(length > MAX_LENGTH)
		{
			GRand * rand = g_rand_new();
			g_assert(rand);
			int rand_len = g_rand_int_range(rand, 1, length-1);
			g_rand_free(rand);
			rand = NULL;

			cut(rand_len, 1);
			cut(length - rand_len, 1);
		}
		else
		{
			nums[length]++;
			g_print("%d ", length);
		}
	}
}

static void print_num(int num)
{
	gint i;

	for(i=1; i<=num; i++)
	{
		if(num%i == 0)
		{
			if(isok(i))
			{
				g_print("%d\n", i);
				break;
			}
		}
	}
}

/*static gboolean isok(int len)
{
	gint i;
	gint cup = 0;
	gboolean flag = TRUE;
	gint sum = 0;
	gint numbers[MAX_LENGTH+1];

	for(i=1; i<=MAX_LENGTH; i++)
	{
		numbers[i] = nums[i];
		g_print("%d: %d\n", i, numbers[i]);
	}
	
	g_print("\n-----------%d---------\n", len);
	while(flag)
	{
		cup = 0;
		for(i=MAX_LENGTH; i>0; i--)
		{
			if(cup >= len)
			{
				//g_print("break\n");
				break;
			}
			//for(j=0; j<numbers[i]; j++)
			while(numbers[i] > 0)
			{
				if((cup+i) <= len)
				{
					cup += i;
					numbers[i]--;
					g_print("%d ", i);

					if(cup >= len)
					{
						g_print("\n");
						break;
					}
				}
				else
				{
					break;
				}
			}
		}

		if(cup != len)
		{
			g_print("false cup = %d\n", cup);
			flag = FALSE;
			return FALSE;
		}

		sum = 0;
		for(i=1; i<=MAX_LENGTH; i++)
		{
			//g_print("%d----->%d\n", i, numbers[i]);
			sum += i*numbers[i];
		}
		//g_print("left sum = %d, len=%d\n", sum, len);
		if(sum < len && sum > 0)
		{
			flag = FALSE;
			return FALSE;
		}
		if(sum == 0)
		{
			flag = FALSE;
			return TRUE;
		}
	}
	
	return TRUE;
}*/

static gboolean isok(int numbers[], int elem, int counter, int length);
{
	int i;
	int my_num[MAX_LENGTH];

	for(i=1; i<=MAX_LENGTH; i++)
	{
		my_num[i] = numbers[i]
	}

	for(i=0; i<numbers[elem]; i++)
	{
		counter += i*elem;
		if(counter == length)
		{
			return TRUE;
		}

		if(counter > length)
		{
			return FALSE;
		}

		if(counter < length && elem > 1)
		{
			return isok(numbers, emem-1, counter, length);
		}
		else
		{
			return FALSE;
		}
	}
	return TRUE;
}
