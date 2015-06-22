#include <bits/stdc++.h>

using namespace std;
int main()
{
	int n,p,x;
	scanf("%d %d %d", &n, &p, &x);
	//vector<int> a;
	//vector<long long int> rating;
	int max_index = 0;
	long long int max_rating = 0;
	for(int i = 1; i<=n ; i++)
	{
		long long int temp;
		scanf("%lld",&temp);
		//a.push_back(temp);
		long long int temp_rating;
		temp_rating = temp*p;
		
		//rating.push_back(temp_rating);
		// printf("Rating for applicant %d = %d * %d = %d\n", i,p,temp,temp_rating);
		if(temp_rating > max_rating)
		{
			// printf("New max rating for %d\n", i);
			max_rating = temp_rating;
			// printf("max_rating = %d\n", max_rating);
			max_index = i;
		}
		p = p - x;
	}
	printf("%d\n", max_index);
	return 0;
}