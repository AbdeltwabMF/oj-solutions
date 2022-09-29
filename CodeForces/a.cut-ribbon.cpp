// https://codeforces.com/contest/189/problem/A

#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

#define endl    '\n'

using namespace std;

typedef int64_t  ll;

void Fast() {
    cin.sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

const int dr []     = {-1, 0, 1, 0};
const int dc []     = {0, 1, 0, -1};
const char dir []   = {'U', 'R', 'D', 'L'};
map <char, int> inv = { {'U', 0}, {'R', 1}, {'D', 2}, {'L', 3}};

const int N = 1e2 + 9, M = 2e5 + 9, oo = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int n, a, b, c, dp[4010];

void Solve()
{
    cin >> n >> a >> b >> c;

    memset(dp, 0xc0, sizeof dp);
    dp[0] = 0;

    for(int i = 0; i <= n; ++i)
    {
        if(i >= a && dp[i - a] + 1 > dp[i])
            dp[i] = dp[i - a] + 1;

        if(i >= b && dp[i - b] + 1 > dp[i])
            dp[i] = dp[i - b] + 1;

        if(i >= c && dp[i - c] + 1 > dp[i])
            dp[i] = dp[i - c] + 1;
    }
    cout << dp[n] << endl;
}

int main()
{
    Fast();

    int tc = 1;
    while(tc--) Solve();
}
