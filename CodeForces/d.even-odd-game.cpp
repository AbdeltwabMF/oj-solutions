// https://codeforces.com/contest/1472/problem/D

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

int n, a[N];

void Solve()
{
    cin >> n;

    for(int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n, greater <int> ());

    ll Alice_score = 0, Bob_score = 0, inx = 0;

    for(int i = 0; inx < n; ++i)
    {
        if(i & 1)
        {
            if(a[inx] & 1)
                Bob_score += a[inx++];
            else
                inx++;
        }
        else
        {
            if(a[inx] & 1)
                inx++;
            else
                Alice_score += a[inx++];
        }
    }

    if(Alice_score == Bob_score)
        cout << "Tie" << endl;
    else if(Alice_score > Bob_score)
        cout << "Alice" << endl;
    else
        cout << "Bob" << endl;
}

int main()
{
    Fast();

    int tc = 1; cin >> tc;
    for(int i = 1; i <= tc; ++i)
        Solve();
}
