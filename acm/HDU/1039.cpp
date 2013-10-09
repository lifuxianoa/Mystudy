#include <iostream>

using namespace std;

bool isvowel(char c)
{
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main()
{
	freopen("in.txt", "r", stdin);

	const int MAXLEN = 21;
	char passwd[MAXLEN];

	while(scanf("%s", passwd) != EOF && strcmp(passwd, "end") != 0)
	{
		char *cur = passwd;
		char last = '\0';
		bool flag1 = true, flag2 = true, flag3 = true;
		int vowel_num = 0, vowel_count = 0, consonant_count = 0;

		while(flag1 && flag2 && flag3 && *cur != '\0')
		{
			if (isvowel(*cur))
			{
				vowel_num++;
				vowel_count++;
				consonant_count = 0;
				if (vowel_count >= 3)
				{
					flag2 = false;
					break;
				}
			}
			else
			{
				vowel_count = 0;
				consonant_count++;
				if (consonant_count >= 3)
				{
					flag2 = false;
					break;
				}
			}

			if (*cur == last && !(*cur == 'e' || *cur == 'o'))
			{
				flag3 = false;
				break;
			}
			last = *cur;
			cur++;
		}
		if (vowel_num == 0)
		{
			flag1 = false;
		}

		//printf("flag1=%d, flag2=%d, flag3=%d\n", flag1, flag2, flag3);
		printf("<%s> is %sacceptable.\n", passwd, flag1 && flag2 && flag3 ? "" : "not ");
	}

	fclose(stdin);
	return 0;
}
