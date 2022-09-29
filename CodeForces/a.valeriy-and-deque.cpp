// https://codeforces.com/contest/1179/problem/A

/**       In the name of Allah, the Gracious, the Merciful.
*               Praise be to Allah, Lord of the Worlds.
*               **************************************
*
*    I have not failed, I have just found 1000 WAYS that won't work.
*                 __________________________________
*                  Author  : Abd El-Twab  M. Fakhry
*                 __________________________________
*/

#include <ext/rope>
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define  print(arr, l, r)    for(int i = (l); i < (r); cout << arr[i++] << " \n"[i == r])
#define  read(arr, l, r)     for(int i = (l); i < (r); cin >> arr[i++])
#define  repr(i, r, l)       for (int i = r; i > l; i--)
#define  rep(i, l, r)        for (int i = l; i < r; i++)
#define  all(a)              a.begin() , a.end()
#define  RT(n)               return cout << (n) << endl, 0;
#define  sz(a)               (int)a.size()
#define  endl                '\n'
#define  D(x)                cout << #x << " = " << (x) << '\n'
#define  F                   first
#define  S                   second
#define  PB                  push_back
#define  EB                  emplace_back
#define  lsb(x)              (x & -x)
#define  get(n)              find_by_order(n)
#define  sqrt(n)             sqrtl(n)
#define  pow(a, b)           powl(a, b)
#define  indexOf(n)          order_of_key(n)
#define  isPowerOfTwo(x)     (x && !(x & (x - 1)))

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

typedef long long            ll;
typedef unsigned long long   ull;

/**---------------------->>  Constants  <<-----------------------**/

const double    Pi      = 2 * acos(0.0),    Euler = 2.71828182845904523536,
                Epsln   = 1e-9,           GoldenR = (1 + sqrtl(5.0)) / 2;

const ll        MgcPrim = 2305843009213693951;
const int       MxsZ    = (int)1e5 + 9,        oo = 0x3f3f3f3f,
 		        ModB2   = (1 << 30) + 7,   ModBT7 = (int)1e9 + 7, ModBT = (int)1e9;

/**---------------->>  Functions & Shortcuts  <<-----------------**/

template <class T>
T Gcd(T a, T b) { return b ? Gcd(b, a % b) : a; }

template <class T>
T Unique(T v) { return v.erase(unique(all(v)), v.end()), v; }

template <class T>
T Lcm(T a, T b) { return a / Gcd(a, b) * 1ll * b; }

template <class T> /** Phi(a * b) = Phi(a) * Phi(b) where a and b Prime Factors and k their power **/
T Phi(T a, T k) { return pow(a, k - 1) * (a - 1); }

template <class T>
using indexed_set = tree <T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update >;

template <class T>
using matrix = vector < vector <T> >;

template <class T>
using min_heap = priority_queue < T, vector <T>, greater <T> >;

/** Watch **/

template <class T>
string ToString(T x) { stringstream sout; sout << x; return sout.str(); }

#ifndef BFS
int dx8[8] = { 1, -1, 0, 0, 1, 1, -1, -1 }, dx4[4] = { 0, 0, 1,-1};
int dy8[8] = { 0, 0, 1, -1, 1, -1, 1, -1 }, dy4[4] = { 1,-1, 0, 0};
#endif // BFS

/**------------------>>  Fast input / output  <<-----------------**/

void Fast()
{
    cin.sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

/**----------------->>  input / output Files  <<-----------------**/

void File()
{
    #ifdef FIO
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
   	#endif // FIO
}

/**------------------>>  Initialization gap  <<------------------**/

ll m, in;
int n, q, x, a, b;
deque <int> dq;
vector <pair <int, int>> ABs;

void Solve()
{
    cin >> n >> q;
    for(int i = 0; i < n; ++i)
    {
        cin >> x; dq.push_back(x);
    }

    ABs.push_back(make_pair(0, 0));

    for(int i = 0; i < 2 * n - 1; ++i)
    {
        ABs.push_back(make_pair(dq[0], dq[1]));
        a = dq[0], b = dq[1];
        dq.pop_front(); dq.pop_front();

        if(a > b)
            dq.push_front(a), dq.push_back(b);
        else
            dq.push_front(b), dq.push_back(a);
    }

    while(q--)
    {
        cin >> m;

        if(m < n * 2 - 1)
            cout << ABs[m].F << " " << ABs[m].S << endl;
        else if(m >= n * 2 - 1)
        {
            in = m % (n - 1) == 0 ? (n - 1) + (n - 1) : m % (n - 1) + (n - 1);
            cout << ABs[in].F << " " << ABs [in].S << endl;
        }
    }
}

/**------------------------->>  Main  <<-------------------------**/

int main()
{
    Fast(); File(); Solve();
}
