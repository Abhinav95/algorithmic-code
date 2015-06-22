#include <bits/stdc++.h>

int main()
{
	int T;
	char c;
	scanf("%d%*c",&T);
	while(T--)
	{
		int sum=0;
		int flag = 0;
		int first;
		int iter = 0;
		bool actual_sum_greater = false;
		int actual_sum = 0;
		while( (c=getchar_unlocked())!='\n')
		{
			if(flag == 0) {
				first = c - '0';
				flag = 1;
			}
			iter++;
			if(not actual_sum_greater) {
				actual_sum += c -'0';
				if(actual_sum > 9) {
					actual_sum_greater = true;
				}
			}
			sum = ( sum%9 + (c - '0') )%9;
		}
		if(iter == 1) 
		{
			sum>9-sum?printf("%d\n",9-sum):printf("%d\n",sum);
		}
		else 
		{
			if(sum>9-sum)
			{
				printf("%d\n",9-sum);
			}
			else 
			{
				if(first < 5 and sum != 0 and actual_sum_greater) {
					printf("%d\n",sum);
				}
				else if(first < 5 and sum != 0 and not actual_sum_greater) {
					printf("%d\n",9 - sum);
				}
				else {
					printf("%d\n",sum);
				}
			}
		}
	}
}