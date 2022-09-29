// https://codeforces.com/contest/1428/problem/A

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

void File() {
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
}

const int N = 1e5 + 9, M = 1e4 + 9, oo = 0x3f3f3f3f;

const ll INF  = 0x3f3f3f3f3f3f3f3f;
const ll mINF = 0xc0c0c0c0c0c0c0c0;

const int dr [] = {-1, 0, 1, 0};
const int dc [] = {0, 1, 0, -1};

int _x1, _y1, x2, y2;

void Solve()
{
    cin >> _x1 >> _y1 >> x2 >> y2;
    if(_x1 == x2)
        cout << abs(_y1 - y2) << endl;
    else if(_y1 == y2)
        cout << abs(_x1 - x2) << endl;
    else
        cout << abs(_x1 - x2) + abs(_y1 - y2) + 2 << endl;
}

int main()
{
    Fast();

    int tc = 1; cin >> tc;
    for(int i = 1; i <= tc; ++i)
        Solve();
}
