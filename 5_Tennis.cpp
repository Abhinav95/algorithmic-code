#include <bits/stdc++.h>

int main()
{
	int T;
	char c;
	scanf("%d%*c",&T);
	while(T--)
	{
		int a=0;
		int b=0;
		int win=0;
		while( (c=getchar())!='\n')
		{
			if(c-'0'==0)
			{
				b++;
			}
			else
			{
				a++;
			}

		}
		if(a >= 11 or b >= 11)
			{
				if(a>=b+2)
					win=1;
				if(b>=a+2)
					win=0;
			}
		win?printf("WIN\n"):printf("LOSE\n");
	}
}