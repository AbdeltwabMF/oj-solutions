// https://codeforces.com/contest/622/problem/C

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
#define  Unique(n)           (n).erase(unique(all(n)), (n).end())
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
#define  clr(arr, x)         memset(arr, x, sizeof(arr))
#define  isPowerOfTwo(x)     (x && !(x & (x - 1)))

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

typedef long long            ll;
typedef unsigned long long   ull;

/**---------------------->>  Constants  <<-----------------------**/

const double    Pi    = 2 * acos(0.0),  Euler = 2.71828182845904523536,
                Error = 1e-9,           GoldenR = (1 + sqrtl(5.0)) / 2;

const ll   Magic = 2305843009213693951;
const int  MxsZ  = (int)2e5 + 9,  oo = 0x3f3f3f3f;
const int  ModP2 = (1 << 30) + 7, ModPT7 = (int)1e9 + 7, ModPT = (int)1e9;

/**---------------->>  Functions & Shortcuts  <<-----------------**/

template <class T>
T Gcd(T a, T b) { return b ? Gcd(b, a % b) : a; }

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
string toString(T x) { stringstream sout; sout << x; return sout.str(); }

#ifdef BFS
int dx8[8] = { 1, -1, 0, 0, 1, 1, -1, -1 }, dx4[4] = { 0, 0, 1,-1};
int dy8[8] = { 0, 0, 1, -1, 1, -1, 1, -1 }, dy4[4] = { 1,-1, 0, 0};
#endif // BFS

/**------------------>>  Fast input / output  <<-----------------**/

void Fast()
{
    cin.sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin.exceptions(cin.failbit);
}

/**----------------->>  input / output Files  <<-----------------**/

void File()
{
    #ifdef FINO
    freopen("new.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
}

/**------------------>>  Initialization gap  <<------------------**/

int n, m, l, r, x, a[MxsZ], nxt[MxsZ];

inline void Solve()
{
	cin >> n >> m;
	read(a, 0, n);

	nxt[n - 1] = -1;
	repr(i, n - 2, -1) 
		nxt[i] = a[i] == a[i + 1] ? nxt[i + 1] : i + 2; 

	while(m--)
	{
		cin >> l >> r >> x;
		cout << (a[--l] == x && nxt[l] <= r ? nxt[l] : a[l++] != x ? l : -1) << endl;
	}
}

/**------------------------->>  Main  <<-------------------------**/

int main()
{
    Fast(); File(); Solve(); 
}