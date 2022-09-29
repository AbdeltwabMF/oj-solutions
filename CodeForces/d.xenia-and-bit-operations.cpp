// https://codeforces.com/contest/339/problem/D

/** resources:
	1. https://codeforces.com/blog/entry/15729
	2. https://codeforces.com/blog/entry/15890
	3. https://codeforces.com/blog/entry/18051
**/

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

class SegmentTree
{
    vector <ll> sTree;
    vector <ll> lazyTree;
    vector <int> localArr;
    int NP2, oo = 0x3f3f3f3f; /** the number of elements in the array as a power of 2 **/
    int LOG;
    ll INF = 0x3f3f3f3f3f3f3f3f;

  public :
    template <class T>
    SegmentTree(T _begin, T _end)
    {
        NP2 = 1;
        int n = _end - _begin;
        while(NP2 < n) NP2 <<= 1;

        LOG = log2(NP2);
        sTree.assign(NP2 << 1, 0);
        lazyTree.assign(NP2 << 1, 0);
        localArr.assign(NP2 + 1, 0);

        __typeof(_begin) i = _begin;
        for(int j = 1; i != _end; i++, ++j)
            localArr[j] = *i;

        build(1, 1, NP2, LOG);
    }

    void build(int p, int l, int r, int lg)
    {
        if(l == r) {
            sTree[p] = localArr[l];
            return;
        }

        build(left(p),  l,     mid(l, r), lg - 1);
        build(right(p), mid(l, r) + 1, r, lg - 1);

        if(lg & 1)
            sTree[p] = (sTree[left(p)] | sTree[right(p)]);
        else
            sTree[p] = (sTree[left(p)] ^ sTree[right(p)]);
//        cout << p << " " << sTree[p] << endl;
    }

    void update_point(int inx, int delta)
    {
        inx += NP2 - 1;
        sTree[inx] = delta;

        int level = 0;
        while(inx > 1)
        {
            inx >>= 1;
            level++;

            if(level & 1)
                sTree[inx] = (sTree[left(inx)] | sTree[right(inx)]);
            else
                sTree[inx] = (sTree[left(inx)] ^ sTree[right(inx)]);
        }
    }

    void update_range(int ul, int ur, int delta) {
        update_range(ul, ur, delta, 1, 1, NP2);
    }

    ll query(int ql, int qr) {
        return query(ql, qr, 1, 1, NP2, LOG);
    }

  private :
    void update_range(int ul, int ur, int delta, int p, int l, int r)
    {
        if(isOutside(ul, ur, l, r))
            return;

        if(isInside(ul, ur, l, r)) {
            sTree[p] += delta;
            lazyTree[p] += delta;
            return;
        }

        propagate(p, l, r);

        update_range(ul, ur, delta, left(p),  l,     mid(l, r));
        update_range(ul, ur, delta, right(p), mid(l, r) + 1, r);

        sTree[p] = min(sTree[left(p)], sTree[right(p)]);
    }

    ll query(int ql, int qr, int p, int l, int r, int level)
    {
        if(isOutside(ql, qr, l, r))
            return INF;

        if(isInside(ql, qr, l, r))
            return sTree[p];

        propagate(p, l, r);

        int lf = query(ql, qr, left(p),  l,     mid(l, r), level - 1);
        int rg = query(ql, qr, right(p), mid(l, r) + 1, r, level - 1);

        if(level & 1)
            return (lf | rg);
        else
            return (lf ^ rg);
    }

    void propagate(int p, int l, int r)
    {
        if(lazyTree[p]) {
            sTree[left(p)]  += lazyTree[p];
            sTree[right(p)] += lazyTree[p];

            if(l != r) {
                lazyTree[left(p)]  += lazyTree[p];
                lazyTree[right(p)] += lazyTree[p];
            }
            lazyTree[p] = 0;
        }
    }

    inline bool isInside(int ql, int qr, int sl, int sr) {
        return (ql <= sl && sr <= qr);
    }

    inline bool isOutside(int ql, int qr, int sl, int sr) {
        return (sr < ql || qr < sl);
    }

    inline int mid (int l, int r) {
        return ((l + r) >> 1);
    }

    inline int left(int p) {
        return (p << 1);
    }

    inline int right(int p) {
        return ((p << 1) | 1);
    }
};

int n, q, x, y, val;
vector <int> a;
stringstream ss;
string line;


void Solve()
{
    cin >> n >> q;

    n = (1 << n);
    a.resize(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];

    SegmentTree st(a.begin(), a.end());

    while(q--)
    {
        cin >> x >> val;
        st.update_point(x, val);
        cout << st.query(1, n) << endl;
    }
}

int main()
{
    Fast();

    int tc = 1;
    for(int i = 1; i <= tc; ++i)
        Solve();
}
