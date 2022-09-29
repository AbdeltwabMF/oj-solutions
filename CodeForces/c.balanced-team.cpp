// https://codeforces.com/contest/1133/problem/C

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
    freopen("output.out",  "r", stdout);
}

const int N = 3e5 + 9, M = 6e5 + 9, oo = 0x3f3f3f3f, Mod = 1e9 + 7;
const ll INF = 0x3f3f3f3f3f3f3f3f;

class UnionFind
{
    vector <int> par;
    vector <int> siz;
    int num_sets;
    size_t sz;

  public:
    UnionFind() : par(1, -1), siz(1, 1), num_sets(0), sz(0) {}
    UnionFind(int n) : par(n + 1, -1), siz(n + 1, 1), num_sets(n), sz(n) {}

    int find_set(int u)
    {
        assert(u <= sz);

        int leader;
        for(leader = u; ~par[leader]; leader = par[leader]);

        for(int next = par[u]; u != leader; next = par[next]) {
            par[u] = leader;
            u = next;
        }
        return leader;
    }

    bool same_set(int u, int v) {
        return find_set(u) == find_set(v);
    }

    bool union_set(int u, int v) {
        if(same_set(u, v)) return false;

        int x = find_set(u);
        int y = find_set(v);

        if(siz[x] < siz[y]) swap(x, y);

        par[y] = x;
        siz[x] += siz[y];

        --num_sets;
        return true;
    }

    int number_of_sets() {
        return num_sets;
    }

    int size_of_set(int u) {
        return siz[find_set(u)];
    }

    size_t size() {
        return sz;
    }

    void clear() {
        par.clear();
        siz.clear();
        sz = num_sets = 0;
    }

    void assign(size_t n) {
        par.assign(n + 1, -1);
        siz.assign(n + 1,  1);
        sz = num_sets = n;
    }

    map < int, vector <int> > groups(int st) {
        map < int, vector <int> > ret;

        for(size_t i = st; i < sz + st; ++i)
            ret[find_set(i)].push_back(i);

        return ret;
    }
};

int Head[N], Next[M], To[M];
int n, m, d, ne, degree[N], u, v;

void addEdge(int from, int to) {
    Next[++ne] = Head[from];
    Head[from] = ne;
    To[ne] = to;
    degree[from]++;
    degree[to]++;
}

int a[N];

void Solve()
{
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);

    int best = 0, cur;
    for(int i = 0; i < n; ++i)
    {
        cur = upper_bound(a, a + n, a[i] + 5) - a - i;
        if(cur > best) best = cur;
    }

    cout << best << endl;
}


int main()
{
    Fast();

    int tc = 1;
    for(int i = 1; i <= tc; ++i)
        Solve();
}
