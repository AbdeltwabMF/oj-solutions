// https://codeforces.com/contest/230/problem/A

	#include <bits/stdc++.h>

	using namespace std;

	int main()
	{
		int s, n;
		cin >> s >> n;

		pair <int, int> arr[n];
		for(int i = 0; i < n; i++)
		{
			cin >> arr[i].first >> arr[i].second;
		}

		sort(arr, arr + n);
		bool flag = true;

		for(int i = 0; i < n; i++)
		{
			if(s <= arr[i].first)
			{	flag = false;
				break;
			}
			else
			{
				s += arr[i].second;
			}
		}

		if(!flag)
		cout << "NO" << endl;
		else cout << "YES" << endl;	
	}