// https://codeforces.com/contest/872/problem/C

#pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define endl        '\n'
#define Min(a, b)   (((a) < (b)) ? (a) : (b))
#define Max(a, b)   (((a) > (b)) ? (a) : (b))

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

const int N = 1e5 + 9, M = 2e6 + 9, oo = 0x3f3f3f3f, Mod = 1e9 + 7;
ll INF = 0x3f3f3f3f3f3f3f3f;

int q, n;

void Solve()
{
	cin >> q;
	while(q--)
    {
        cin >> n;
        int ans = -1;

        if(n % 4 == 0)
            ans = n / 4;
        else if(n % 4 == 1 && n >= 9)
            ans = 1 + (n - 9) / 4;
        else if(n % 4 == 2 && n >= 6)
            ans = 1 + (n - 6) / 4;
        else if(n % 4 == 3 && n >= 6 + 9)
            ans = 2 + (n - 6 - 9) / 4;

        cout << ans << endl;
    }
}

int main()
{
    Fast();

    int tc = 1;
    for(int i = 1; i <= tc; ++i)
        Solve();
}
