// https://codeforces.com/contest/1472/problem/B

#pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define endl        '\n'

using namespace std;

typedef int64_t    ll;
typedef __int128 i128;
typedef long double ld;

void Fast() {
    cin.sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

void File() {
    freopen("shops.in",   "r", stdin);
}

const int N = 3e5 + 9, M = N << 1, oo = 0x3f3f3f3f, Mod = 1e9 + 7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const ld eps = 1e-9;

int n, twos, ones, x;

void Solve()
{
    cin >> n;
    twos = ones = 0;

    for(int i = 1; i <= n; ++i)
    {
        cin >> x;
        (x == 2) ? ++twos : ++ones;
    }

    twos &= 1;
    if(twos)
    {
        ones -= 2;
        if(ones >= 0)
        {
            if(ones % 2 == 0)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else
             cout << "NO" << endl;
    }
    else
    {
        if(ones % 2 == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}

int main()
{
    Fast();

    int tc = 1; cin >> tc;
    for(int i = 1; i <= tc; ++i)
        Solve();
}
