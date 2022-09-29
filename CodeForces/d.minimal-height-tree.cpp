// https://codeforces.com/contest/1437/problem/D

#pragma GCC optimize ("Ofast")
 
#include <bits/stdc++.h>

#define endl    '\n'

using namespace std;
 
typedef int64_t  ll;
 
void Fast() {
    cin.sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

const int N = 2e5 + 9, M = 4e5 + 9, oo = 0x3f3f3f3f;
ll INF = 0x3f3f3f3f3f3f3f3f;
 
int Head[N], Next[M], To[M], dis[N], ne, m, u, v;

void addEdge(int from, int to) {
    Next[++ne] = Head[from];
    Head[from] = ne;
    To[ne] = to;
}
 
int n, a[N];
 
void _clear() {
    memset(Head, 0,   sizeof(Head[0]) * (n + 2));
    ne = 0;
}
 
void BFS(int src)
{
    memset(dis, 0x3f, sizeof(dis[0]) * (n + 2));
    queue <int> Q;
    Q.push(src);
    dis[src] = 0;
 
    int node;
    while(Q.size())
    {
        node = Q.front(); Q.pop();
        for(int i = Head[node]; i; i = Next[i]) if(dis[To[i]] == oo)
        {
            dis[To[i]] = dis[node] + 1;
            Q.push(To[i]);
        }
    }
}
 
void Solve()
{
    cin >> n;
    _clear();
 
    queue <int> Q;
    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        Q.push(a[i]);
    }
 
    Q.pop();
    for(int i = 1; i <= n; ++i)
    {
 
        int last = -1;
        if(Q.size())
            last = Q.front(), Q.pop();
 
        if(last != -1)
        {
            addEdge(a[i], last);
            addEdge(last, a[i]);
        }
        else
            continue;
 
        while(Q.size() && Q.front() > last)
        {
            last = Q.front(); Q.pop();
            addEdge(a[i], last);
            addEdge(last, a[i]);
        }
    }
 
    BFS(1);
 
    int ans = -1;
    for(int i = 1; i <= n; ++i)
        if(dis[i] > ans) ans = dis[i];
 
    cout << ans << endl;
}
 
int main()
{
    Fast();
    int tc = 1; cin >> tc;
    while(tc--)  Solve();
}