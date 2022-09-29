// https://codeforces.com/contest/1467/problem/A

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
string s = "7890123456";

void Solve()
{
    cin >> n;
    if(n == 1) { cout << "9" << endl; return; }
    else cout << "98";
    for(int i = 2; i < n; ++i) cout << s[i % 10]; cout << endl;
}

int main()
{
    Fast();

    int tc = 1; cin >> tc;
    for(int i = 1; i <= tc; ++i)
        Solve();
}
