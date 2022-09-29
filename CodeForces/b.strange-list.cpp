// https://codeforces.com/contest/1471/problem/B

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

int n, a[N], x, pre[N];
ll sum;

void Solve()
{
    cin >> n >> x;

    sum = 0;
    memset(pre, '?', sizeof(pre[0]) * (n + 2));

    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        sum += a[i];

        int cnt = 0, z = a[i];
        while(z % x == 0) z /= x, cnt++;

        pre[i] = min(cnt, pre[i - 1]);
    }

    sum += *min_element(pre + 1, pre + n + 1) * sum;
    int stop = find(pre + 1, pre + 1 + n, *min_element(pre + 1, pre + n + 1)) - pre;

    for(int i = 1; i < stop; ++i) sum += a[i];

    cout << sum << endl;
}

int main()
{
    Fast();

    int tc = 1; cin >> tc;
    for(int i = 1; i <= tc; ++i)
        Solve();
}
