// https://codeforces.com/contest/776/problem/B

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

const int N = 1e6;

void Fast() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int almostP[N];

void sieve(ll n) {
    fill(almostP+2, almostP + n + 1, 1);
    for(int i = 2; i <= n; ++i)
        if(almostP[i] == 1)
            for (int j = i + i; j <= n; j += i) almostP[j] = 2;

    if(n <= 3)
        cout << 1 << endl;
    else
        cout << 2 << endl;
    for(int i = 2; i <= n; ++i)
        cout << almostP[i] << " ";
}

int main() {
    int n;
    cin >> n;
    sieve(n+1);
}
