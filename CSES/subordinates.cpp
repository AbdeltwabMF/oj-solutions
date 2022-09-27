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

const int N = 3e5 + 9, M = 6e5 + 9, oo = 0x3f3f3f3f, Mod = 1e9 + 7;
ll INF = 0x3f3f3f3f3f3f3f3f;

int Head[N], Next[M], To[M], Par[N];
int sbtree[N];
int ne, n, m, u, v, w;

void addEdge(int from, int to) {
    Next[++ne] = Head[from];
    Head[from] = ne;
    To[ne] = to;
}

void _clear() {
    memset(Head, 0, sizeof(Head[0]) * (n + 2));
    memset(Par, -1, sizeof(Par[0])  * (n + 2));
    ne = 0;
}

void dfs(int node, int par = -1) {
    sbtree[node] = 1;
    for(int i = Head[node]; i; i = Next[i]) if(To[i] != par)
    {
        dfs(To[i], node);
        sbtree[node] += sbtree[To[i]];
    }
}

void Solve()
{
    cin >> n;
    _clear();

    for(int i = 2; i <= n; ++i) {
        cin >> u;
        addEdge(u, i);
    }

    dfs(1);

    for(int i = 1; i <= n; ++i)
        cout << sbtree[i] - 1 << " \n"[i == n];
}

int main()
{
    Fast();

    int tc = 1;
    for(int i = 1; i <= tc; ++i)
        Solve();
}
