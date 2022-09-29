// https://codeforces.com/contest/617/problem/E

#pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define endl        '\n'

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

const int N = 2e5 + 9, M = 2e5 + 9, oo = 0x3f3f3f3f, Mod = 1e9 + 7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int BLK = 256;

struct query
{
    int l, r, id, blk;

    query() = default;
    query(int _l, int _r, int _id) {
        l = _l;
        r = _r;
        id = _id;
        blk = l / BLK;
    }

    bool operator < (const query other) const {
        if(blk ^ other.blk)
            return blk < other.blk;
        return (blk & 1) ? r < other.r : r > other.r;
    }
} queries[M];

ll cur, res[M];
int freq[M << 5], k;

void add(int val) {
    cur += freq[(val ^ k)];
    ++freq[val];
}

void remove(int val) {
    --freq[val];
    cur -= freq[(val ^ k)];
}

ll get_res() {
    return cur;
}

int cur_l, cur_r, l, r, n, m, a[N];

void Solve()
{
    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        a[i] ^= a[i - 1];
    }

    for(int i = 1; i <= m; ++i) {
        cin >> l >> r;
        queries[i] = query(l, r, i);
    }

    sort(queries + 1, queries + 1 + m);

    cur_l = 1, cur_r = 0;
    for(int i = 1; i <= m; ++i)
    {
        int ql = queries[i].l - 1;
        int qr = queries[i].r;

        while(cur_r < qr) add(a[++cur_r]);
        while(cur_l > ql) add(a[--cur_l]);
        while(cur_r > qr) remove(a[cur_r--]);
        while(cur_l < ql) remove(a[cur_l++]);

        res[queries[i].id] = get_res();
    }

    for(int i = 1; i <= m; ++i)
        cout << res[i] << "\n";
}

int main()
{
    Fast();

    int tc = 1;
    for(int i = 1; i <= tc; ++i)
        Solve();
}
