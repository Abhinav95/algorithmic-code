#include <bits/stdc++.h>

using namespace std;

#define MOD 100000007

int prime = 10;

unsigned long long fast_exp(int base, int exp) {
    unsigned long long res=1;
    while(exp>0) {
       if(exp%2==1) res=(res*base)%MOD;
       base=(base*base)%MOD;
       exp/=2;
    }
    return res;
}

unsigned long long CalculateHash(const vector<int>& fwd_hash, int i, int j)
{
    if(i>j)
        return -1;
    unsigned long long ret = (fwd_hash[j]%MOD - (fast_exp(prime, 2*(j-i+1))%MOD)*(fwd_hash[i-1]%MOD)%MOD)%MOD;
    return ret;
}

int main()
{
	string s;
	cin >> s;
	vector<int> fwd_hash(s.size() + 1,0);
	vector<int> bwd_hash(s.size() + 1,0);
	for(auto i=1;i <= s.size();i++) {
		fwd_hash[i] = ((fwd_hash[i-1]%MOD*prime%MOD)%MOD + s[i - 1]%MOD)%MOD;
	}
	int K = s.size();
	for(auto i = 1;i<=s.size();i++) {
		bwd_hash[i] = ((bwd_hash[i-1]%MOD*prime%MOD)%MOD + s[K-i]%MOD)%MOD;
	}
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int i,j,k,l;
		scanf("%d %d %d %d",&i,&j,&k,&l);
		// out side 
		if( k>j or l<i )
		{
			printf("Case 0 ");
			if( CalculateHash(fwd_hash,k,l) == CalculateHash(bwd_hash,k,l) ) {
				printf("Yes\n");
			}
			else {
				printf("No\n");
			}
		}
		else
		{
			// pure overlap
			if(k>=i and l<=j) 
			{
				printf("Case 1 ");
				if( CalculateHash(fwd_hash,j-i-l,j-i-k) == CalculateHash(bwd_hash,j-i-l,j-i-k) ) 
				{
					printf("Yes\n");
				}
				else 
				{
					printf("No\n");
				}
			}
			// one side
			else if(i >= k and i <= l and j >= l)
			{
				printf("Case 2 ");
				if( (CalculateHash(fwd_hash,k,i) + CalculateHash(bwd_hash,j,j-i-l)) == (CalculateHash(bwd_hash,k,i) + CalculateHash(fwd_hash,j,j-i-l)) )
				{
					printf("Yes\n");
				}
				else 
				{
					printf("No\n");
				}

			}
			// another side
			else if(k >= i and k <= j and l >= j)
			{

				printf("Case 3 ");
				if( (CalculateHash(fwd_hash,j,l) + CalculateHash(bwd_hash,k-i-j,i)) == (CalculateHash(bwd_hash,j,l) + CalculateHash(fwd_hash,k-i-j,i)) ) 
				{
					printf("Yes\n");
				}
				else 
				{
					printf("No\n");
				}
			}
			// reverse pure
			else 
			{
				printf("Case 4 ");
				if( (CalculateHash(fwd_hash,k,i) + CalculateHash(bwd_hash,i,j)+ CalculateHash(fwd_hash,j,l)) == (CalculateHash(bwd_hash,k,i) + CalculateHash(fwd_hash,i,j)+ CalculateHash(bwd_hash,j,l)) ) 
				{
					printf("Yes\n");
				}
				else 
				{
					printf("No\n");
				}
			}
		}
	}
}