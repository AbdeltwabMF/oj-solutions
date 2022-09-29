// https://codeforces.com/contest/1445/problem/A

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

const int N = 1e6 + 9, M = 2e6 + 9, oo = 0x3f3f3f3f;
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
        for(int cur = -1; cur ^ node;)
        {
            in_stack[cur = Stack[--top]] = false;
            compID[cur] = ID;
            ++compSize[ID];
        }
    }
}

vector <int> primes;
bool isPrime[N];

void sieve(ll x)
{
    int basis [3] = {2, 3, 5};
    int wheel [8] = {7, 11, 13, 17, 19, 23, 29, 1};
    int inc   [8] = {4, 2, 4, 2, 4, 6, 2, 6};
    int inx[31];

    memset(inx,        -1, sizeof inx);
    memset(isPrime, true, sizeof isPrime);

    for(int i : basis) if(x >= i)
            primes.push_back(i);

    for(int i = 0; i < 8; ++i)
        inx[wheel[i]] = i;

    int c = 0;
    for(ll i = 7; i <= x; i += inc[c++])
    {
        if(isPrime[i])
        {
            primes.push_back(i);
            int d = inx[i % 30];

            for(ll j = i * i; j <= x; j += i * inc[d++])
            {
                isPrime[j] = false;
                if(d == 8) d = 0;
            }
        }
        if(c == 8) c = 0;
    }
}

vector <int> Factorization(ll n)
{
    vector <int> ret;

    for(int prime : primes)
    {
        if((ll)prime * prime > n) break;
        if(n % prime) continue;

        while(n % prime == 0)
            ret.push_back(prime), n /= prime;
    }
    if(n > 1)
        ret.push_back(n);
    return ret;
}

ll inc_exc(ll p, ll q)
{
    vector <int> factors = Factorization(q);

    i128 Mx = -1;
    int sz = factors.size();

    for(int mask = 1; mask < (1 << sz); ++mask) {
        i128 mult = p;

        for(int i = 0; i < sz; ++i)
            if (mask & (1 << i)) {
                mult *= factors[i];
            }

        if(mult % q) Mx = Max(Mx, mult);
    }
    return (ll)Mx;
}

void Yes(bool ok)
{
    cout << (ok ? "Yes" : "No") << endl;
}

int x, a[N], b[N];

void Solve()
{
    cin >> n >> x;

    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n; ++i) cin >> b[i];
    sort(b, b + n, greater <int> ());

    bool ok = true;
    for(int i = 0; i < n; ++i)
        if(b[i] + a[i] > x) ok = false;

    Yes(ok);
}

int main()
{
    Fast();

    sieve(1000000);

    int tc = 1; cin >> tc;
    for(int i = 1; i <= tc; ++i)
        Solve();
}
