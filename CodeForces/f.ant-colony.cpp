// https://codeforces.com/contest/474/problem/F

#pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>

using namespace std;

#define MIN(a, b)   ((a) <= (b) ? (a) : (b))
#define endl        '\n'

typedef int64_t      ll;
typedef __int128_t i128;
typedef long double  ld;

const int N = 3e5 + 9, M = N << 1, oo = 0X3F3F3F3F;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const ld epsilon = 1e-9;

void Fast() {
    cin.sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

template <class T, class F = function <bool(const T &, const T &)> >
class SegmentTree
{
    vector <T> _A;
    vector <vector <T>> MSST;
    vector <T> Gcd;
    F func;
    int _N;

public :
    template <class iter>
    SegmentTree(iter _begin, iter _end, const F _func = less <T> ()) : func(_func)
    {
        _N = distance(_begin, _end);
        _N = (1 << (int)ceil(log2(_N)));

        _A.assign(_N + 1, oo);
        MSST.assign(_N << 1, vector <T> (1, 0));
        Gcd.assign(_N << 1, 0);

        __typeof(_begin) i = _begin;
        for(int j = 1; i != _end; ++i, ++j)
            _A[j] = *i;

        build(1, 1, _N);
    }

    void build(int p, int l, int r)
    {
        if(l == r) {
            MSST[p][0] = _A[l];
            Gcd[p] = _A[l];
            return;
        }

        int mid = (l + r) >> 1;

        build(p + p, l, mid);
        build(p + p + 1, mid + 1, r);

        vector <T> & x = MSST[p + p];
        vector <T> & y = MSST[p + p + 1];

        tie(Gcd[p], MSST[p]) = merge(x, y);
    }

    tuple <T,T,T> query(int ql, int qr) {
        return query(ql, qr, 1, 1, _N);
    }

private :
    tuple <T,T,T> query(int ql, int qr, int p, int l, int r)
    {
        if(r < ql || qr < l)
            return {oo, 0, 0};

        if(ql <= l && r <= qr)
        {
            return {*MSST[p].begin(), upper_bound(MSST[p].begin(), MSST[p].end(), *MSST[p].begin()) - lower_bound(MSST[p].begin(), MSST[p].end(), *MSST[p].begin()),
                    Gcd[p]};
        }

        int mid = (l + r) >> 1;

        const tuple <T,T,T> & x = query(ql, qr, p + p, l, mid);
        const tuple <T,T,T> & y = query(ql, qr, p + p + 1, mid + 1, r);

        if(get<0>(x) == get<0>(y))
            return {get<0>(x), get<1>(x) + get<1>(y), __gcd(get<2>(x), get<2>(y))};
        else if(get<0>(x) < get<0>(y))
            return {get<0>(x), get<1>(x), __gcd(get<2>(x), get<2>(y))};
        else
            return {get<0>(y), get<1>(y), __gcd(get<2>(x), get<2>(y))};
    }

    pair <T, vector <T> > merge(vector <T> & x, vector <T> & y)
    {
        vector <T> ret(x.size() + y.size());
        T gcd = 0;
        x.emplace_back(oo);
        y.emplace_back(oo);

        for (int i = 0, j = 0, k = 0; i < ret.size(); ++i) {
            if(x[j] <= y[k])
                ret[i] = x[j], j += (x[j] != oo);
            else
                ret[i] = y[k], k += (y[k] != oo);
            gcd = __gcd(gcd, ret[i]);
        }
        x.pop_back(); y.pop_back();
        return make_pair(gcd, ret);
    }
};

int n, a[N], q, l, r;

void Solve()
{
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];

    SegmentTree <int> st(a, a + n);

    cin >> q;
    while(q--)
    {
        cin >> l >> r;
        int gcd, mn, rep;
        tie(mn, rep, gcd) = st.query(l, r);
        if(gcd == mn)
            cout << (r - l + 1) - rep << endl;
        else
            cout << (r - l + 1) << endl;
    }
}

int main()
{
    Fast();

    int tc = 1;
    for (int i = 0; i < tc; ++i) {
        Solve();
    }
}
