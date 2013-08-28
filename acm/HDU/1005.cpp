/*
 * 1000.cpp
 *
 *  Created on: 2013-8-26
 *      Author: Administrator
 */

#include <iostream>

using namespace std;

int f[1010];

int main()
{
	freopen("in.txt", "r", stdin);
	int i,n,a,b;
	f[1]=1;f[2]=1;
	while(scanf("%d %d %d", &a, &b, &n) != EOF
			&& !(a==0 && b==0 && n==0))
	{
		for(i=3;i<=49;i++)
		{
			f[i]=(a*f[i-1]+b*f[i-2])%7;
		}
		n=n%49;
		if(n==0)
		{
			printf("%d\n", f[49]);
		}
		else
		{
			printf("%d\n", f[n]);
		}
	}

	fclose(stdin);
	return 0;
}
