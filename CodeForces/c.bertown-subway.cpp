// https://codeforces.com/contest/884/problem/C

#pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define endl        '\n'
#define Min(a, b)   (((a) < (b)) ? (a) : (b))
#define Max(a, b)   (((a) > (b)) ? (a) : (b))

using namespace std;

typedef int64_t  ll;

void Fast() {
    cin.sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

void File() {
    freopen("input.in",  "r", stdin);
    freopen("output.out", "w", stdout);
}

const int N = 1e5 + 9, M = 2e6 + 9, oo = 0x3f3f3f3f;
ll INF = 0x3f3f3f3f3f3f3f3f;

int Head[N], To[M], Next[M], dfs_num[N], dfs_low[N], n, m, u, v, tax;
int dfs_timer, top, ne, ID;
int Stack[N], compID[N], compSize[N];
bool in_stack[N];

void addEdge(int from, int to) {
    Next[++ne] = Head[from];
    Head[from] = ne;
    To[ne] = to;
}

void _clear() {
    memset(Head,     0, sizeof(Head[0])     * (n + 2));
    memset(compID,   0, sizeof(compID[0])   * (n + 2));
    memset(dfs_num,  0, sizeof(dfs_num[0])  * (n + 2));
    memset(compSize, 0, sizeof(compSize[0]) * (n + 2));
    ne = dfs_timer = top = ID = 0;
}

void Tarjan(int node)
{
    dfs_num[node] = dfs_low[node] = ++dfs_timer;
    in_stack[Stack[top++] = node] = true;

    for(int i = Head[node]; i; i = Next[i])
    {
        if(dfs_num[To[i]] == 0)
            Tarjan(To[i]);

        if(in_stack[To[i]])
            dfs_low[node] = Min(dfs_low[node], dfs_low[To[i]]);
    }

    if(dfs_num[node] == dfs_low[node])
    {
        ++ID;
        for(int cur = -1; cur ^ node;) {
            in_stack[cur = Stack[--top]] = false;
            compID[cur] = ID;
            ++compSize[ID];
        }
    }
}

template <class T>
void bubble_sort(T _begin, T _end, int round) {
    const int sz = _end - _begin;
    int localArray[sz];

    __typeof(_begin) k = _begin;
    for(int j = 0; k != _end; ++k, ++j)
        localArray[j] = *k;

    round = min(round, sz);
    for(int i = 0; i < round; ++i) /* n rounds -> n_th element **/
        for(int j = 0; j < sz - 1; ++j) if(localArray[j] > localArray[j + 1])
            swap(localArray[j], localArray[j + 1]);

    k = _begin;
    for(int j = 0; k != _end; ++k, ++j)
        *k = localArray[j];
}

class UnionFind
{
    vector <int> par;
    vector <int> siz;
    int num_sets;
    size_t sz;

  public:
    UnionFind(int n) : par(n + 1, -1), siz(n + 1, 1), num_sets(n), sz(n) {}

    int find_set(int u) {
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

    int sets() {
        return num_sets;
    }

    int s_size(int u) {
        return siz[find_set(u)];
    }

    size_t size() {
        return sz;
    }

    vector < vector <int> > all_sets(int st) {
        map < int, vector <int> > tmp;
        vector < vector <int> > ret;

        for(size_t i = st; i < sz + st; ++i)
            tmp[find_set(i)].push_back(i);

        for(auto i : tmp)
            ret.push_back(i.second);
        return ret;
    }
};

template <class T>
void selection_sort(T _begin, T _end, int round)
{
    const int sz = _end - _begin;
    int localArray[sz];

    __typeof(_begin) k = _begin;
    for(int i = 0; k != _end; ++i, ++k)
        localArray[i] = *k;

    int MnInx;
    round = min(sz, round);
    for(int i = 0; i < round; ++i)
    {
        MnInx = i;
        for(int j = i + 1; j < sz; ++j) if(localArray[j] > localArray[MnInx])
            MnInx = j;

        swap(localArray[MnInx], localArray[i]);
    }

    k = _begin;
    for(int i = 0; k != _end; ++i, ++k)
        *k = localArray[i];
}

int a[N], vis[N];

void Solve()
{
    cin >> n;
    UnionFind uf(n);

    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        uf.union_set(i, a[i]);
    }

    vector <int> component_size;
    for(int i = 1; i <= n; ++i) if(!vis[uf.find_set(i)])
    {
        vis[uf.find_set(i)] = true;
        component_size.emplace_back(uf.s_size(i));
    }

    selection_sort(component_size.begin(), component_size.end(), 2);

    ll ans = 0;
    for(int i = 2; i < component_size.size(); ++i)
        ans += component_size[i] * 1ll * component_size[i];

    cout << ans + ((component_size[0] + component_size[1]) * 1ll * (component_size[0] + component_size[1])) << endl;
}

int main()
{
    Fast();

    int tc = 1;
    for(int i = 1; i <= tc; ++i)
        Solve();
}
