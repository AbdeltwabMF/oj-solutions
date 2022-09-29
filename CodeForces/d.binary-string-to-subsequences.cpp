// https://codeforces.com/contest/1399/problem/D

/**         In the name of Allah, the Gracious, the Merciful.
*                 Praise be to Allah, Lord of the Worlds.
*                 **************************************
*
*      I have not failed, I have just found 1000 WAYS that won't work.
*
*          كُودٌ قد حَوي دررًا بعينِ الحسنِ ملحوظة .. لِهذا قُلتُ تنبيهًا حقوقُ النقلِ محفوظة
*
*                   __________________________________
*                    Author  : Abd El-Twab  M. Fakhry
*                   __________________________________
*/

#pragma GCC optimize ("Ofast")

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
#include <bits/stdc++.h>

#define  print(arr, l, r)    for(int i = (l); i < (r); cout << arr[i++] << " \n"[i == r])
#define  read(arr, l, r)     for(int i = (l); i < (r); cin >> arr[i++])
#define  watch(x)            cout << #x << " = " << (x) << '\n'
#define  RT(n)               return cout << (n) << endl, 0;
#define  repr(i, r, l)       for (int i = r; i > l; i--)
#define  rep(i, l, r)        for (int i = l; i < r; i++)
#define  isPowerOfTwo(x)     (x && !(x & (x - 1)))
#define  all(a)              a.begin() , a.end()
#define  get(n)              find_by_order(n)
#define  indexOf(n)          order_of_key(n)
#define  sz(a)               (int)a.size()
#define  pow(a, b)           powl(a, b)
#define  lsb(x)              (x & -x)
#define  sqrt(n)             sqrtl(n)
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

const double    Pi      = 2 * acos(0.0),    Euler = 2.71828182845904523536,
                Epsln   = 1e-9,           GoldenR = (1 + sqrtl(5.0)) / 2;

const lll       SprPrim = 170141183460469231731687303715884105727;
const ll        MgcPrim = 2305843009213693951;
const int       N       = (int)1e5 + 9,        oo = 0x3f3f3f3f;
const int       Mod     = (int)1e9 + 7;

/**---------------->>  Functions & Shortcuts  <<-----------------**/

template <class T> T Unique(T v) { sort(all(v)); return v.erase(unique(all(v)), v.end()), v; }

template <class T> T    Gcd(T a, T b) { return b ? Gcd(b, a % b) : a; }
template <class T> auto Lcm(T a, T b) { return a / (lll)Gcd(a, b) * b; }

/** Phi(a * b) = Phi(a) * Phi(b) where a and b Prime Factors and k their power **/
template <class T> auto Phi(T a, int k) { return (lll)pow(a, k - 1) * (a - 1); }

template <class T>
T ExGcd(T a, T b, T & x, T & y)
{
    if(!a) { x = 0, y = 1; return b; }

    T xx, yy, g = ExGcd(b % a, a, xx, yy);
    x = yy - b / (lll)a * xx; y = xx;
    return g;
}

template <class T> T Normal(T n) { n %= Mod; (n < 0) && (n += Mod); return n; }
template <class T> T Inv(T a) { T x, y; assert(ExGcd(a, Mod, x, y) == 1); return Normal(x); }

/** Modular Calculations **/
template <class T> auto _add(T a, T b, T Mod) { return (lll)a + b >= Mod ? (lll)a + b - Mod : a + b; }
template <class T> T    _sub(T a, T b) { return a - b < 0 ? a - b + Mod : a - b; }
template <class T> T    _mul(T a, T b) { return T((lll)a * b % Mod); }
template <class T> T    _div(T a, T b) { return _mul(a, Inv(b)); }

template <class T1, class T2>
auto ModExp(T1 a, T2 n)
{
    a %= Mod; lll result = 1, tmp = a;
    while(n)
    {
        if(n & 1) result = (result * tmp) % Mod;
        tmp = (tmp * tmp) % Mod;  n >>= 1;
    }
    return result;
}

/** Data Structures **/
template <class T> using indexed_set = tree <T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update >;
template <class T> using min_heap = priority_queue < T, vector <T>, greater <T> >;
template <class T> using matrix = vector < vector <T> >;

template <class T> string ToString(T x) { stringstream sout; sout << x; return sout.str(); }

#ifndef BFS
int dx8[8] = { 1, -1, 0, 0, 1, 1, -1, -1 }, dx4[4] = { 0, 0, 1,-1};
int dy8[8] = { 0, 0, 1, -1, 1, -1, 1, -1 }, dy4[4] = { 1,-1, 0, 0};
#endif

/**-------------------->> Conversions <<--------------------**/

template <class T> string IntToStr(T x)
{
    int sn = 1; if(x < 0) sn = -1, x *= sn; string s = "";

    do
    {
        s = "0123456789"[x % 10] + s, x /= 10;
    } while(x);
    return (sn == -1 ? "-" : "") + s;
}

lll StrTolll(string x)
{
    lll ret = (x[0] == '-' ? 0 : x[0] - '0');
    for(int i = 1; i < sz(x); ++i) ret = ret * 10 + (x[i] - '0');
    return ret * (x[0] == '-' ? -1 : 1);
}

/** Overloading operator <<, operator >> to accept an __int128 **/

istream & operator >> (istream & in, lll & i) noexcept
{
    string s; in >> s; i = StrTolll(s); return in;
}

ostream & operator << (ostream & os, const lll i) noexcept
{
    os << IntToStr(i); return os;
}

/**------------------>>  Fast input / output  <<-----------------**/

void Fast()
{
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

/**----------------->>  input / output Files  <<-----------------**/

void File()
{
    #ifdef FIO
    freopen("input.txt", "r", stdin);
    freopen("output.out", "w", stdout);
   	#endif
}

/**------------------>>  Initialization gap  <<------------------**/

int n;
string s;
stack <int> lastZero, lastOnes;
static int mx;

void Solve()
{
    cin >> n >> s; mx = 1;
    vector <int> pos(n+2);
    lastOnes = lastOnes = stack <int> ();
    lastOnes.push(0); lastZero.push(0);

    for(int i = 0; i < n; ++i)
    {
        if(s[i] == '1')
        {
            if(lastZero.top() > 0) lastOnes.push(lastZero.top()), lastZero.pop();
            else lastOnes.push(mx++);
            pos[i] = lastOnes.top();
        }
        else
        {
            if(lastOnes.top() > 0) lastZero.push(lastOnes.top()), lastOnes.pop();
            else lastZero.push(mx++);
            pos[i] = lastZero.top();
        }
    }
    cout << mx - 1 << endl;
    print(pos, 0, n);

    // 000 010101 1010101 11 1100
    // 123 444444 3333333 21 5656
    // 123 444444 3333333 21 56650

    // 000 010101 1010101 11 1100
    // 123 411111 2111111 34 5612

    // 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
    // 1 2 3 4 5 6 7 8 9 10111213141516171819202122
}

void MultiTest(bool Test)
{
    int _t_ = 1; (Test) && (cin >> _t_);
    while(_t_--) Solve();
}

/**------------------------->>  Main  <<-------------------------**/

int main()
{
    Fast(); File(); MultiTest(true);
}
