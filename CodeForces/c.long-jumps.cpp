// https://codeforces.com/contest/1472/problem/C

#pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define endl        '\n'

using namespace std;

typedef int64_t    ll;
typedef __int128 i128;
typedef long double ld;

void Fast() {
    cin.sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

void File() {
    freopen("shops.in",   "r", stdin);
}

const int N = 3e5 + 9, M = N << 1, oo = 0x3f3f3f3f, Mod = 1e9 + 7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const ld eps = 1e-9;

int n, a[N];

void Solve()
{
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];

    for(int i = n; i > 0; --i)
    {
        if(a[i] + i <= n) a[i] += a[a[i] + i];
    }

    cout << *max_element(a + 1, a + n + 1) << endl;
}

int main()
{
    Fast();

    int tc = 1; cin >> tc;
    for(int i = 1; i <= tc; ++i)
        Solve();
}
