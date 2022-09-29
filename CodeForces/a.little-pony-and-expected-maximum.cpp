// https://codeforces.com/contest/453/problem/A

#pragma  GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define endl '\n'
# define trav(G, i, u, v)  for(int i = G.Head[u], v; i && (v = G.To[i], true); i = G.Next[i])

using namespace std;

typedef int64_t ll;
typedef uint64_t ull;
typedef __int128_t i128;
typedef __uint128_t ui128;
typedef long double ld;

void Fast() {
    istream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

const int N = 2e5 + 9, M = N << 1, oo = 0x3f3f3f3f, Mod = 1e9 + 7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const ld eps = 1e-9;
const int BLK = 512;

void File() {
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
}

// Graph begin
class Graph {
public:
    vector<int> Head, Next, To;
    int ne, sz;

    Graph() {
        ne = 0;
        sz = 0;
    }

    Graph(int V, int E) : sz(V) {
        Head.assign(V + 9, 0);
        Next.resize(E + 9);
        To.resize(E + 9);
        ne = 0;
    }

    void clear() {
        ne = 0;
        fill(Head.begin(), Head.end(), 0);
    }

    void addEdge(int from, int to) {
        Next[++ne] = Head[from];
        Head[from] = ne;
        To[ne] = to;
    }

    void addBiEdge(int u, int v) {
        addEdge(u, v);
        addEdge(v, u);
    }
};
// Graph end

int color[N];

// Eulerian Tour begin
int euler_tour[(N << 1) + 99], First[N], Last[N], Color[(N << 1) + 99], euler_timer;
Graph G;

void dfs(int u, int p = -1) {
    First[u] = ++euler_timer;
    for (int i = G.Head[u]; i; i = G.Next[i]) {
        if (G.To[i] != p) dfs(G.To[i], u);
    }
    Last[u] = ++euler_timer;
}
// Eulerian Tour end

// Mo Algorithm begin
struct query {
    int l, r, id, blk;

    query() = default;

    query(int _l, int _r, int _id) : l(_l), r(_r), id(_id) {
        blk = l / BLK;
    }

    bool operator<(const query others) const {
        if (blk ^ others.blk)
            return blk < others.blk;
        return (blk & 1) ? r < others.r : r > others.r;
    }
} queries[N];

int frq[N], cur, ans[N];

void add(int id) {
    cur += (++frq[Color[id]] == 1);
}

void remove(int id) {
    cur -= (--frq[Color[id]] == 0);
}

int get_answer() {
    return cur;
}
// Mo Algorithm end

int n, m;

void Solve() {
    cin >> m >> n;

    double answer = m;
    for (int i = 1; i < m; ++i) {
        answer -= pow((double) i / m, n);
    }
    cout << fixed << setprecision(10) << answer << endl;
}

int main() {
    Fast();
    // File();

    int tc = 1; // cin >> tc;
    for (int i = 1; i <= tc; ++i) {
        Solve();
    }
}