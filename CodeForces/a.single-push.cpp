// https://codeforces.com/contest/1253/problem/A

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

int Dx8[8] = { 1, -1, 0, 0, 1, 1, -1, -1 }, Dx4[4] = { 0, 0, 1,-1};
int Dy8[8] = { 0, 0, 1, -1, 1, -1, 1, -1 }, Dy4[4] = { 1,-1, 0, 0};

const double inf  = 1.0 / 0.0,      pi  = 2 * acos(0.0),   error = 1e-9;
const int    MxsZ = (int)1e5 + 6,   mod = (1 << 30) + 7,      oo = 0x3f3f3f3f;

ll Gcd(ll a, ll b)     { return b ? a % b ? Gcd(b, a % b) : b : a; }
ll Lcm(ll a, ll b)     { return a * b / Gcd(a, b); }

void Fast()
{
    cin.sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin.exceptions(cin.failbit);
}

void File()
{
    freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
}

/**----------------------->>  Template  <<------------------------*/

int t, n, a[MxsZ], b[MxsZ], _start, _end, k;

/**------------------>>  Initialization gap  <<-------------------*/

int main()
{
    Fast();

    cin >> t;
    while(t--)
    {
        cin >> n; read(a, 0, n); read(b, 0, n);
        _start = -1;
        rep(i, 0, n)
        {
            if(_start == -1 && a[i] != b[i])
                { _start = i, k = b[i] - a[i]; if(k < 0) { cout << "NO" << endl; goto j; } }
            else if(a[i] != b[i]) _end = i;
        }
        if(_start == -1) cout << "YES" << endl;
        else
        {
            rep(i, _start, _end + 1)
                { a[i] += k; if(a[i] != b[i]) { cout << "NO" << endl; goto j; } }
            cout << "YES" << endl;
        }
        j:
            continue;
    }
}

/** stuff you should look for
	  1- int overflow
	  2- array bounds
	  3- Division by 0, indexOutOfBoundary
	  4- value of mod
	  5- special cases ( n = 1 or n = max(n) )
      6- set, map TLE
      7- erase during traversal
	  do something instead of nothing and stay organized, Keep Calm
*/
