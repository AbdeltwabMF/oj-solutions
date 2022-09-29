// https://codeforces.com/contest/405/problem/A

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int m;
	cin >> m;
	
	int arr[m];
	for(int i = 0; i < m; ++i)
	{
		cin >> arr[i];
	}

	sort(arr + 0, arr + m);

	for(int i = 0; i < m; ++i)
	{
		cout << arr[i] << " ";
	}
}