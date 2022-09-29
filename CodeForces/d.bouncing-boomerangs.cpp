// https://codeforces.com/contest/1428/problem/D

#pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define endl      '\n'
#define mp        make_pair

using namespace std;

typedef int64_t    ll;
typedef __int128 i128;

void Fast() {
    cin.sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

void File() {
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
}

void kill()
{
    cout << -1 << endl;
    exit(0);
}

const int N = 2e5 + 9, M = 1e4 + 9, oo = 0x3f3f3f3f;

const ll INF  = 0x3f3f3f3f3f3f3f3f;
const ll mINF = 0xc0c0c0c0c0c0c0c0;

const int dr [] = {-1, 0, 1, 0};
const int dc [] = {0, 1, 0, -1};

int n, a[N];

void Solve()
{
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];

    vector <pair <int, int> > ans;

    queue <int> one, others;
    for(int i = n; i; --i)
    {
        if(a[i] == 1)
        {
            ans.emplace_back(mp(i, i));
            one.push(i);
        }
        else if(a[i] == 2)
        {
            if(one.empty())
                kill();

            ans.push_back(mp(one.front(), i));
            one.pop();
            others.push(i);
        }
        else if(a[i] == 3)
        {
            if(one.empty() && others.empty())
                kill();

            if(others.size())
            {
                ans.push_back(mp(i, i));
                ans.push_back(mp(i, others.front()));
                others.pop();
            }
            else
            {
                ans.push_back(mp(i, i));
                ans.push_back(mp(i, one.front()));
                one.pop();
            }
            others.push(i);
        }
    }

    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); ++i)
        cout << ans[i].first << " " << ans[i].second << endl;
}

int main()
{
    Fast();

    int tc = 1;
    for(int i = 1; i <= tc; ++i)
        Solve();
}
