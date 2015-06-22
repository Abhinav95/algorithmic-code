#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	long long int sum=0;
	cin >> n;
	string s;
	cin >> s;
	// for(int length = 1; length <= n ;length++)
	// {
	// 	for(int start_index = 0; start_index <= n - length; start_index++)
	// 	{
	// 		sum += (s[start_index] == s[start_index+length-1]);
	// 	}
	// }

	map<char,long long int> values;
	for(int i = 0; i < n; i++)
	{
		values[s[i]] = 0;
	}
	for(int i = 0; i < n; i++)
	{
		values[s[i]] += 1;
	}
	for(auto it = values.begin(); it!=values.end();it++)
	{
		// cout << it->first << " : " << it->second << endl;
		sum += it->second*(it->second+1)/2;
	}

	cout << sum << endl;
	return 0;
}