// https://codeforces.com/contest/727/problem/A

/**         In the name of Allah, the Gracious, the Merciful.
*                 Praise be to Allah, Lord of the Worlds.
*                 **************************************
*
*      I have not failed, I have just found 1000 WAYS that won't work.
*
*        © كُودٌ قد حَوى دررًا بعينِ الحسنِ ملحوظة .. لِهذا قُلتُ تنبيهًا حقوقُ النقلِ محفوظة
*
*                   __________________________________
*                    @Author : Abd El-Twab  M. Fakhry
*                   __________________________________
*/

#pragma GCC optimize ("Ofast")

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include "bits/stdc++.h"
#include <ext/rope>

#define  rforeach(c, _it)    for(__typeof((c).rbegin()) _it = (c).rbegin(); _it != (c).rend(); ++_it)
#define  foreach(c, _it)     for(__typeof((c).begin()) _it = (c).begin(); _it != (c).end(); ++_it)
#define  print(_a, _l, _r)   for(int _i = (_l); _i < (_r); cout << _a[_i++] << " \n"[_i == (_r)])
#define  read(_a, _l, _r)    for(int _i = (_l); _i < (_r); cin >> _a[_i++])
#define  dbg(x)              cerr << #x << " = " << x << endl;
#define  repr(i, r, l)       for (int i = (r); i > (l); --i)
#define  rep(i, l, r)        for (int i = (l); i < (r); ++i)
#define  isPowerOfTwo(x)     ((x) && !((x) & ((x) - 1)))
#define  all(a)              (a).begin(), (a).end()
#define  get(n)              find_by_order((n))
#define  indexOf(n)          order_of_key((n))
#define  pow(a, b)           powl((a), (b))
#define  sz(a)               (int)a.size()
#define  lsb(x)              ((x) & -(x))
#define  sqrt(n)             sqrtl((n))
#define  endl                '\n'

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

typedef unsigned long long  ull;
typedef long double         lld;
typedef __uint128_t        ulll;
typedef long long            ll;
typedef __int128            lll;

/**---------------------->>  Constants  <<-----------------------**/

const double    Pi      = 2 * acos(0.0),    Euler = 2.71828182845904523536;
const double    Epsln   = 1e-9,           GoldenR = (1 + sqrtl(5.0)) / 2;

const int       N       = (int)1e5 + 9,         M = (int)1e6 + 6;       
const int       Mod     = (int)1e9 + 7,        oo = 0x3f3f3f3f;

/**---------------->>  Functions & Shortcuts  <<-----------------**/

#if __cplusplus >= 201402L

/** Random Generator **/
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <class T> T Rand(T a, T b) { return uniform_int_distribution <ll> (a, b)(rng); /** [a, b] **/}

template <class T> string to_string(T x)
{
    int sn = 1; if(x < 0) sn = -1, x *= sn; string s = "";
    do { s = "0123456789"[x % 10] + s, x /= 10; } while(x);
    return (sn == -1 ? "-" : "") + s;
}

lll str_to_int128(string x)
{
    lll ret = (x[0] == '-' ? 0 : x[0] - '0');
    for(int i = 1; i < sz(x); ++i) ret = ret * 10 + (x[i] - '0');
    return ret * (x[0] == '-' ? -1 : 1);
}

/** Overloading operator << and >> to accept an __int128 **/
istream & operator >> (istream & in, lll & i) noexcept { string s; in >> s; i = str_to_int128(s); return in; }
ostream & operator << (ostream & os, const lll i) noexcept { os << to_string(i); return os; }

template <class T> T Unique(T v) { return v.erase(unique(all(v)), v.end()), v; }
template <class T> T ExGcd(T a, T b, T & x, T & y)
{
    if(!a) { x = 0, y = 1; return b; }
    T xx, yy, g = ExGcd(b % a, a, xx, yy);
    x = yy - b / (lll)a * xx; y = xx;
    return g;
}

/** Phi(a * b) = Phi(a) * Phi(b) where a and b Prime Factors and k their power **/
template <class T> auto Phi(T a, int k) { return (lll)pow(a, k - 1) * (a - 1); }
template <class T> T    Normal(T n) { n %= Mod; (n < 0) && (n += Mod); return n; }
template <class T> T    ModMulInv(T a) { T x, y; assert(ExGcd(a, Mod, x, y) == 1); return Normal(x); }
template <class T> T    Gcd(T a, T b) { return b ? Gcd(b, a % b) : a; }
template <class T> auto Lcm(T a, T b) { return a / (lll)Gcd(a, b) * b; }

/** Modular Calculations **/
template <class T> auto _add(T a, T b, T Mod) { return (lll)a + b >= Mod ? (lll)a + b - Mod : a + b; }
template <class T> T    _sub(T a, T b) { return a - b < 0 ? a - b + Mod : a - b; }
template <class T> T    _mul(T a, T b) { return T((lll)a * b % Mod); }
template <class T> T    _div(T a, T b) { return _mul(a, ModMulInv(b)); }
template <class T> T    ModExp(T a, T n)
{
    a %= Mod; T result = 1;
    while(n) { if(n & 1) result = _mul(result, a); a = _mul(a, a);  n >>= 1; }
    return result;
}

/** Data Structures **/
template <class T> using indexed_set = tree <T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update >;
template <class T> using min_heap = priority_queue < T, vector <T>, greater <T> >;
template <class T> using matrix = vector < vector <T> >;
#endif

/** for Debugging purpose **/
template <typename F, typename S>
ostream & operator << (ostream & os, const pair <F, S> & p) 
{ return os << "(" << p.first << ", " << p.second << ")"; }

template <typename F, typename S>
ostream & operator << (ostream & os, const map <F, S> & _mp) 
{ os << "["; foreach(_mp, it) { if(it != _mp.begin()) os << ", "; os << it->first << " = " << it->second; } return os << "]"; }

template <typename T>
ostream & operator << (ostream & os, const vector <T> & _v) 
{ os << "{"; foreach(_v, it) { if(it != _v.begin()) os << ", "; os << *it; } return os << "}"; }

template <typename T>
ostream & operator << (ostream & os, const set <T> & _st) 
{ os << "["; foreach(_st, it) { if(it != _st.begin() ) os << ", "; os << *it; } return os << "]"; }

template <typename T>
ostream & operator << (ostream & os, const indexed_set <T> & _ist) 
{ os << "["; foreach(_ist, it) { if(it != _ist.begin() ) os << ", "; os << "(" << _ist.indexOf(*it) << ", " << *it << ")"; } return os << "]"; }

#ifdef BFS
int dx8[8] = { 1, -1, 0, 0, 1, 1, -1, -1 }, dx4[4] = { 0, 0, 1,-1};
int dy8[8] = { 0, 0, 1, -1, 1, -1, 1, -1 }, dy4[4] = { 1,-1, 0, 0};
#endif

/** intput / output Control **/
void Fast() { cin.sync_with_stdio(0); cin.tie(0); cout.tie(0); }
void File(string i = "input.in", string o = "o.out")
{
    #ifdef FIO
    freopen(i, "r", stdin);
    freopen(o, "w", stdout);
    #endif
}

/**------------------>>  Initialization gap  <<------------------**/

int a, b;

bool isPossible(ll x)
{
    if(x > b) return false;
    if(x == b) return true;

    return isPossible(x * 2) || isPossible(x * 10 + 1);
}

vector<int> trans;

void getTrans(ll x)
{
    if(isPossible(x * 2))
    {
        trans.push_back(2 * x);
        getTrans(x * 2);
    }
    else if(isPossible(x * 10 + 1))
    {
        trans.push_back(x * 10 + 1);
        getTrans(x * 10 + 1);
    }
}


void Solve()
{
    cin >> a >> b;
    if(isPossible(a)) getTrans(a);

    if(sz(trans))
    {
        cout << "YES" << endl << 1 + sz(trans) << endl << a << " ";
        foreach(trans, it) cout << *it << " ";
    }
    else cout << "NO" << endl;
}

void MultiTest(bool Tests)
{
    int _tc = 1; (Tests) && (cin >> _tc); while(_tc--) Solve();
}

/**------------------------->>  Main  <<-------------------------**/

int main()
{
    Fast(); File(); MultiTest(false);
}

/**
*   1e-18 != -1e18
*   Bitwise operators should not be performed on operands with different data types
*   (long long & 1) WRONG! but -->> (long long & 1ll) is Acceptable
*   Bitwise operators should be used only with unsigned integer operands
*   Create an empty data structure ---> Ex. st = stack <int> () , vc = vector < vector <int> > ();
*   is Modulo = 1e9 + 7 ? or something else..
*/
