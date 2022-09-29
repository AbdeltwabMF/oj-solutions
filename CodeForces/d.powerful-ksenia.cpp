// https://codeforces.com/contest/1438/problem/D

#pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define endl        '\n'

using namespace std;

typedef int64_t    ll;
typedef __int128 i128;

void Fast() {
    cin.sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

void File() {
    freopen("input.in",  "r", stdin);
    freopen("output.out", "w", stdout);
}

const int N = 2e5 + 9, M = 4e5 + 9, oo = 0x3f3f3f3f, Mod = 1e9 + 7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int dr [] = {-1, 0, 1, 0};
const int dc [] = {0, 1, 0, -1};

int n, m, A[N], xorientation;

void kill() {
    cout << "NO" << endl; exit(0);
}

void get() {
    for(int i = 2; i <= n; i += 2)
        cout << 1 << " " << i << " " << i + 1 << endl;
    for(int i = 2; i + 2 <= n; i += 2)
        cout << 1 << " " << i << " " << i + 1 << endl;
}

void Solve()
{
    cin >> n; xorientation = 0;
    for(int i = 0; i < n; ++i) cin >> A[i], xorientation ^= A[i];

    if(n & 1)
    {
        cout << "YES" << endl << (n - 2) << endl;
        get();
    }
    else
    {
        if(xorientation) kill();
        cout << "YES" << endl << (--n - 2) << endl;
        get();
    }
}

int main()
{
    Fast();

    int tc = 1;
    for(int i = 1; i <= tc; ++i)
        Solve();
}
