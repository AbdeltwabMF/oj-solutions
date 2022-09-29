// https://codeforces.com/contest/161/problem/D

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

int Head[N], Next[M], To[M];
int ne, u, v, n, m, k;
int dp[N][555];
ll ans;

void addEdge(int from, int to) {
    Next[++ne] = Head[from];
    Head[from] = ne;
    To[ne] = to;
}

void dfs(int node, int par = -1) {
    dp[node][0] = 1; // reachable via 0 edges is node itself
    for(int i = Head[node]; i; i = Next[i]) if(To[i] != par) {
            dfs(To[i], node);

            for(int j = 0; j < k; ++j)
                ans += dp[node][j] * dp[To[i]][k - j - 1];

            for(int j = 0; j < k; ++j)
                dp[node][j + 1] += dp[To[i]][j];
        }
}

void Solve()
{
    cin >> n >> k;

    for(int i = 1; i < n; ++i) {
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }

    dfs(1);
    cout << ans << endl;
}

int main()
{
    Fast();

    int tc = 1;
    for(int i = 1; i <= tc; ++i)
        Solve();
}
