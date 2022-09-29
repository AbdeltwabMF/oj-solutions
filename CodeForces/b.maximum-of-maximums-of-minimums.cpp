// https://codeforces.com/contest/872/problem/B

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

int n, k, a[N];

void Solve()
{
	cin >> n >> k;
	for(int i = 0; i < n; ++i) cin >> a[i];

	if(k == 1)
        cout << *min_element(a, a + n) << endl;
    else if(k >= 3)
        cout << *max_element(a, a + n) << endl;
    else
    {
        cout << max(a[0], a[n - 1]) << endl;
    }
}

int main()
{
    Fast();

    int tc = 1;
    for(int i = 1; i <= tc; ++i)
        Solve();
}
