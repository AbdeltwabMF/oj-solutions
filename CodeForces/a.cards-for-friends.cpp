// https://codeforces.com/contest/1472/problem/A

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

ll w, h, n;

void Solve()
{
    cin >> w >> h >> n;

    int w_2 = 0, h_2 = 0;

    while(w % 2 == 0) w /= 2, w_2++;
    while(h % 2 == 0) h /= 2, h_2++;

    cout << (((1ll << h_2) * (1ll << w_2)) >= n ? "YES" : "NO") << endl;
}

int main()
{
    Fast();

    int tc = 1; cin >> tc;
    for(int i = 1; i <= tc; ++i)
        Solve();
}
