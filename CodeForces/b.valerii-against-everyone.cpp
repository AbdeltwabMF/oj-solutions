// https://codeforces.com/contest/1438/problem/B

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

int n, m, A[N];

void Solve()
{
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> A[i];
    sort(A, A + n);
    cout << (((unique(A, A + n) - A) < n) ? "YES" : "NO") << endl;
}

int main()
{
    Fast();

    int tc = 1; cin >> tc;
    for(int i = 1; i <= tc; ++i)
        Solve();
}
