// https://codeforces.com/contest/1266/problem/B

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

#define  read(arr, l, r)     for(int i = (l); i < (r); cin >> arr[i++])
#define  print(arr, l, r)    for(int i = (l); i < (r); cout << arr[i++] << " \n"[i == r])
#define  rep(i, l, r)        for (int i = l; i < r; i++)
#define  repr(i, r, l)       for (int i = r; i > l; i--)
#define  trav(a, x)          for (auto & a : x)
#define  PQ(T)               priority_queue < T, vector <T> , greater <T> >
#define  Unique(n)           (n).erase(unique(all(n)), (n).end())
#define  endl                '\n'
#define  all(a)              a.begin() , a.end()
#define  NumberOfDigits(n)   ((int)log10(n) + 1)
#define  sz(a)               (int)a.size()
#define  rall(a)             a.rbegin(), a.rend()
#define  rsz(sz)             resize(sz)
#define  ins(x)              insert(x)
#define  debug(x)            cout << #x << " = " << (x) << '\n'
#define  LINE_ON             cout << "line Number = " << __LINE__ << endl
#define  RT(n)               return cout << (n) << endl, 0;
#define  clr(arr, x)         memset(arr, x, sizeof(arr))
#define  F                   first
#define  S                   second
#define  PB                  push_back
#define  EB                  emplace_back
#define  get(n)              find_by_order(n)
#define  indexOf(n)          order_of_key(n)
#define  isPowerOfTwo(x)     (x && !(x & (x - 1)))
#define  Swap(n, k)           n ^= k, k ^= n, n ^= k;

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

template <class T>
using indexed_set = tree <T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update >;
typedef long long            ll;
typedef unsigned int         uint;
typedef unsigned long long   ull;

int dx8[8] = { 1, -1, 0, 0, 1, 1, -1, -1 }, dx4[4] = { 0, 0, 1,-1};
int dy8[8] = { 0, 0, 1, -1, 1, -1, 1, -1 }, dy4[4] = { 1,-1, 0, 0};

const double pi = 2 * acos(0.0), Euler = 2.71828182845904523536D,   error = 1e-9;
const int  MxsZ = (int)1e6 + 6, modP2 = (1 << 30) + 7, modPT = 1e9 + 7,  oo = 0x3f3f3f3f;

ll Gcd(ll a, ll b)     { return b ? Gcd(b, a % b) : a; }
ll Lcm(ll a, ll b)     { return a * b / Gcd(a, b); }

template <class T>
string toString(T x) { stringstream sout; sout << x; return sout.str(); }

void Fast()
{
    cin.sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin.exceptions(cin.failbit);
}

void File()
{
    //freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
}

/**----------------------->>  Template  <<-----------------------**/

ll a, t;

void solve()
{
    cin >> a; cout << ((a % 14 && a % 14 <= 6 && a > 6) ? "YES" : "NO") << endl;
}

/**------------------>>  Initialization gap  <<------------------**/

int main()
{
    Fast();

    cin >> t;
    while(t--) solve();
}
