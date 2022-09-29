// https://codeforces.com/contest/977/problem/D

#include <bits/stdc++.h>

using namespace std;

void fast() 
{ 
	cin.sync_with_stdio(0); 
	cin.tie(0);cout.tie(0); 
}

long long n, a;
pair <int, long long> arr[101];

int main()
{
    fast();

    cin >> n;
    
	for(int i = 0; i < n; i++) 
	{ 
		cin >> a;
		
		arr[i].second = a; 
		
		while(a % 3 == 0) 
		{
			arr[i].first--; 
			a /= 3;
		} 
	}

	sort(arr, arr+n);
	
	for(int i = 0; i < n; i++)
	{ 
		cout << arr[i].second;
		
		if(i == n) cout << '\n';
		else cout << ' ';
	}
}