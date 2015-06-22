#include <bits/stdc++.h>

using namespace std;

bool is_palindromic(const string& seq, int k, int l)
{
    auto count = seq.size() / 2; // rounded down is fine, as a middle element matches itself
    auto i = k;        // prefer std::begin(seq) in C++14
    auto j = l;       // prefer std::rbegin(seq) in C++14

    for (auto c = 0; c < count; ++c, ++i, --j)
    {
        if (seq[i] != seq[j])
            return false;
    }
    return true; // considers sequences without mismatched characters to be palindromes
}

int main()
{
	string s;
	cin >> s;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int i,j,k,l;
		scanf("%d %d %d %d",&i,&j,&k,&l);
		i--;
		j--;
		k--;
		l--;
		if( k>j or l<i )
		{
			is_palindromic(s,k,l)?printf("Yes\n"):printf("No\n");
		}
		else
		{
			reverse(s.begin()+i,s.begin()+j+1);
			is_palindromic(s,k,l)?printf("Yes\n"):printf("No\n");
			reverse(s.begin()+i,s.begin()+j+1);
		}
	}
}