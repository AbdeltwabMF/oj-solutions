// https://codeforces.com/contest/872/problem/A

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

int n, k, a, cnt[10];

void Solve()
{
	cin >> n >> k;
	int mn1 = oo, mn2 = oo;
	for(int i = 0; i < n; ++i) cin >> a, mn1 = min(mn1, a), cnt[a]++;
	for(int i = 0; i < k; ++i) cin >> a, mn2 = min(mn2, a), cnt[a]++;

	if(mn1 > mn2) swap(mn1, mn2);
	if(*max_element(cnt, cnt + 10) == 2)
    {
        for(int i = 1; i <= 9; ++i)
            if(cnt[i] == 2)
            {
                cout << i << endl;
                exit(0);
            }
    }
    else
        cout << mn1 << mn2 << endl;
}

int main()
{
    Fast();

    int tc = 1;
    for(int i = 1; i <= tc; ++i)
        Solve();
}
