// https://codeforces.com/contest/1471/problem/A

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

int n, a[N], x;
ll Mx, Mn;

void Solve()
{
    cin >> n >> x;
    Mx = Mn = 0;

    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
        Mx += (a[i] + x - 1) / x;
        Mn += a[i];
    }

    cout << (Mn + x - 1) / x << " " << Mx << endl;
}

int main()
{
    Fast();

    int tc = 1; cin >> tc;
    for(int i = 1; i <= tc; ++i)
        Solve();
}
