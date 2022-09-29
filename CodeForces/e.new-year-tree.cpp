// https://codeforces.com/contest/620/problem/E

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

template <class T>
class SegmentTree
{
    vector <T> _A;
    vector <T> ST;
    vector <T> LT;
    int _N;

  public :
    template <class iter>
    SegmentTree(iter _begin, iter _end)
    {
        _N = distance(_begin, _end);
        _N = (1 << (int)ceil(log2(_N)));

        _A.assign(_N + 1,  0);
        ST.assign(_N << 1, 0);
        LT.assign(_N << 1, 0);

        __typeof(_begin) i = _begin;
        for(int j = 1; i != _end; ++i, ++j)
            _A[j] = *i;

        build(1, 1, _N);
    }

    void build(int p, int l, int r)
    {
        if(l == r) {
            ST[p] = (1ll << _A[l]);
            return;
        }

        int mid = (l + r) >> 1;

        build(p + p, l, mid);
        build(p + p + 1, mid + 1, r);

        ST[p] = ST[p + p] | ST[p + p + 1];
    }

    void update(int ul, int ur, int bit) {
        update(ul, ur, bit, 1, 1, _N);
    }

    int query(int ql, int qr) {
        return __builtin_popcountll(query(ql, qr, 1, 1, _N));
    }

    void update(int ul, int ur, int bit, int p, int l, int r)
    {
        if(r < ul || ur < l)
            return;

        if(ul <= l && r <= ur) {
            ST[p] = (1ll << bit);
            LT[p] = (1ll << bit);
            return;
        }

        propagate(p);

        int mid = (l + r) >> 1;
        update(ul, ur, bit, p + p, l, mid);
        update(ul, ur, bit, p + p + 1, mid + 1, r);

        ST[p] = ST[p + p] | ST[p + p + 1];
    }

    long long query(int ql, int qr, int p, int l, int r)
    {
        if(r < ql || qr < l)
            return 0;

        if(ql <= l && r <= qr)
            return ST[p];

        propagate(p);

        int mid = (l + r) >> 1;

        return  query(ql, qr, p + p, l, mid) |
                query(ql, qr, p + p + 1, mid + 1, r);
    }

    void propagate(int p)
    {
        if(LT[p])
        {
            ST[p + p] = LT[p];
            ST[p + p + 1] = LT[p];
            LT[p + p] = LT[p];
            LT[p + p + 1] = LT[p];
            LT[p] = 0;
        }
    }
};

const int N = 4e5 + 9, M = 8e5 + 9, oo = 0x3f3f3f3f, Mod = 1e9 + 7;
ll INF = 0x3f3f3f3f3f3f3f3f;

int Head[N], To[M], Next[M];
ll color[N];
int First[N], Last[N], euler_tour[N << 1], euler_timer;
ll Color[N << 1];
int ne, n, m, u, v;

void addEdge(int from, int to) {
    Next[++ne] = Head[from];
    Head[from] = ne;
    To[ne] = to;
}

void _clear() {
    memset(Head,  0, sizeof(Head[0])  * (n + 2));
    memset(First, 0, sizeof(First[0]) * (n + 2));
    ne = euler_timer = 0;
}

void EulerianTour(int node)
{
    euler_tour[++euler_timer] = node;
    Color[euler_timer] = color[node];
    First[node] = euler_timer;

    for(int i = Head[node]; i; i = Next[i]) if(First[To[i]] == 0) {
            EulerianTour(To[i]);

            euler_tour[++euler_timer] = node;
            Color[euler_timer] = color[node];
        }

    Last[node] = euler_timer;
}

void Solve()
{
    cin >> n >> m;
    _clear();

    for(int i = 1; i <= n; ++i)
        cin >> color[i];

    for(int i = 1; i < n; ++i) {
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }

    EulerianTour(1);
    SegmentTree <ll> st(Color + 1, Color + euler_timer + 1);

    int type, node, newColor;
    while(m--)
    {
        cin >> type >> node;
        if(type == 1)
        {
            cin >> newColor;
            st.update(First[node], Last[node], newColor);
        }
        else
            cout << st.query(First[node], Last[node]) << endl;
    }
}

int main()
{
    Fast();

    int tc = 1;
    for(int i = 1; i <= tc; ++i)
        Solve();
}
