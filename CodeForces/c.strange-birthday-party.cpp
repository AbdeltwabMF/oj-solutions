// https://codeforces.com/contest/1471/problem/C

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

int n, c[N], k[N], m, pre[N];
ll sum;

void Solve()
{
    cin >> n >> m;
    sum = 0;

    for(int i = 0; i < n; ++i)
        cin >> k[i];

    for(int i = 1; i <= m; ++i)
        cin >> c[i];

    sort(k, k + n, greater <int> ());

    int inx = 1;
    for(int i = 0; i < n; ++i)
    {
        if(c[k[i]] > c[inx]) sum += c[inx++];
        else sum += c[k[i]];
    }

    cout << sum << endl;
}

int main()
{
    Fast();

    int tc = 1; cin >> tc;
    for(int i = 1; i <= tc; ++i)
        Solve();
}
