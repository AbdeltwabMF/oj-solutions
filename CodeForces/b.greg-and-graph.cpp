// https://codeforces.com/contest/295/problem/B

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

const int N = 5e2 + 9, M = 1e4 + 9, oo = 0x3f3f3f3f;

int n;
int_fast64_t adj[N][N], dis[N][N];
vector <int> a;

vector <int_fast64_t> Floyd_Warshall()
{
    memcpy(dis, adj, sizeof dis);
    vector <int_fast64_t> ret;

    for(int v = n, k = a[v]; v; --v, k = a[v])
    {
        int_fast64_t sum = 0;
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                if(dis[i][k] + dis[k][j] < dis[i][j])
                    dis[i][j] = dis[i][k] + dis[k][j];

        for(int i = n; i >= v; --i)
            for(int j = n; j >= v; --j)
                    sum += dis[a[i]][a[j]];

        ret.push_back(sum);
    }

    reverse(ret.begin(), ret.end());
    return ret;
}

void Solve()
{
    cin >> n;
    a.resize(n + 1);

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            cin >> adj[i][j];

    for(int i = 1; i <= n; ++i)
        cin >> a[i];

    vector <int_fast64_t> ans = Floyd_Warshall();

    for(int i = 0; i < ans.size(); ++i)
        cout << ans[i] << " \n"[i == ans.size() - 1];
}

int main()
{
    Fast();

    int tc = 1;
    for(int i = 1; i <= tc; ++i)
        Solve();
}
