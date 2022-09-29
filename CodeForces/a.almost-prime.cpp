// https://codeforces.com/contest/26/problem/A

/**
	constraints:
	1 <= n <= 1e8

	Time complexity of this approach is : n lnln √n + O(n)
**/

#pragma  GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define endl      '\n'

using namespace std;

typedef long long  ll;

const int N = 1e5;

void Fast() {
    cin.sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

int almostP[N];

int sieve(ll n)
{
    for(int i = 2; i <= n; ++i)
        if(!almostP[i])
            for (int j = i + i; j <= n; j += i) almostP[j]++;

    int ret = 0;
    for(int i = 2; i <= n; ++i)
        if(almostP[i] == 2) ret++;

    return ret;
}

int main()
{
    int n; cin >> n;
    cout << sieve(n) << endl;
}
