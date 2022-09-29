// https://codeforces.com/contest/1422/problem/B

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

const int N = 100 + 9, M = 1e4 + 9, oo = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
ll mat[N][N];
int n, m;

ll get_tax(vector <int> & a)
{
    ll ret = INF, cur;
    for(int i = 0; i < a.size(); ++i)
    {
        cur = 0;
        for(int j = 0; j < a.size(); ++j)
            cur += abs(a[i] - a[j]);
        ret = min(ret, cur);
    }
    return ret;
}

void Solve()
{
    cin >> n >> m;

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            cin >> mat[i][j];

    int nn = (n + 1) / 2, mm = (m + 1) / 2;

    ll cost = 0;
    for(int i = 1; i <= nn; i++)
        for(int j = 1; j <= mm; ++j)
        {
            vector <int> coll = {mat[i][j]};
            if(i != n - i + 1)
                coll.push_back(mat[n - i + 1][j]);
            if(j != m - j + 1)
                coll.push_back(mat[i][m - j + 1]);
            if(i != n - i + 1 && j != m - j + 1)
                coll.push_back(mat[n - i + 1][m - j + 1]);
            cost += get_tax(coll);
        }

    cout << cost << endl;
}

int main()
{
    Fast();

    int tc = 1; cin >> tc;
    for(int i = 1; i <= tc; ++i)
        Solve();
}
