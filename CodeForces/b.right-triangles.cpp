// https://codeforces.com/contest/52/problem/B

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

const int N = 1e3 + 9, M = 1e3 + 9, oo = 0x3f3f3f3f;

int n, m;
char grid[N][N];
ll sum[3][N];

void Solve()
{
    cin >> n >> m;

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            cin >> grid[i][j];

    for(int i = 1; i <= n; ++i)
    {
        int cur = 0;
        for(int j = 1; j <= m; ++j) if(grid[i][j] == '*') cur++;
        sum[1][i] = cur;
    }

    for(int j = 1; j <= m; ++j)
    {
        int cur = 0;
        for(int i = 1; i <= n; ++i) if(grid[i][j] == '*') cur++;
        sum[2][j] = cur;
    }

    ll ans = 0;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(grid[i][j] == '*')
                ans += (sum[1][i] - 1) * (sum[2][j] - 1);

    cout << ans << endl;
}

int main()
{
    Fast();

    int tc = 1;
    for(int i = 1; i <= tc; ++i)
        Solve();
}
