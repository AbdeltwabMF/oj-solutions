// https://codeforces.com/contest/52/problem/A

/** resources:
	1. https://codeforces.com/blog/entry/15729
	2. https://codeforces.com/blog/entry/15890
	3. https://codeforces.com/blog/entry/18051
**/

#pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define endl      '\n'

using namespace std;

typedef int64_t    ll;
typedef __int128 i128;

void Fast() {
    cin.sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

const int N = 1e6 + 9, M = 1e3 + 9, oo = 0x3f3f3f3f;

ll n, m, a[4], b;

void Solve()
{
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> b, a[b]++;

    cout << a[1] + a[2] + a[3] - max({a[1], a[2], a[3]}) << endl;
}

int main()
{
    Fast();

    int tc = 1;
    for(int i = 1; i <= tc; ++i)
        Solve();
}
