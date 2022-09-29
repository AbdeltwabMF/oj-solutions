// https://codeforces.com/contest/1203/problem/B

/**  In the name of Allah, the Gracious, the Merciful.
*    Praise be to Allah, Lord of the Worlds.
*    **************************************
*
*    I have not failed, I have just found 1000 WAYS that won't work.
*    __________________________________
*     Author  : Abd El-Twab  M. Fakhry
*    __________________________________
*/

#include <ext/rope>
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define  read(arr, l, r)     for(int i = (l); i < (r); cin >> arr[i++])
#define  readi(i, arr, l, r) for(int (i) = (l); (i) < (r); cin >> arr[i++])
#define  print(arr, l, r)    for(int i = (l); i < (r); cout << arr[i++] << " \n"[i == r])
#define  rep(i, l, r)        for (int i = l; i < r; i++)
#define  repr(i, r, l)       for (int i = r; i > l; i--)
#define  PQ(T)               priority_queue < T, vector <T> , greater <T> >
#define  Unique(n)           (n).erase(unique(all(n)), (n).end())
#define  eq(x, y)            (fabs((x)-(y)) <= error)
#define  endl                '\n'
#define  Hello_Friend        fast();
#define  all(a)              a.begin() , a.end()
#define  NumberOfDigits(n)   ((int)log10(n) + 1)
#define  sz(a)               (int)a.size()
#define  precision(n)        cout << fixed << setprecision(n)
#define  debug(x)            cout << #x << " = " << (x) << '\n'
#define  RT(n)               return cout << (n) << endl, 0;
#define  F                   first
#define  S                   second
#define  PB                  push_back
#define  EB                  emplace_back
#define  of(n)               find_by_order(n)
#define  position_of(n)      order_of_key(n)
#define  parityOfOnes(x)     __builtin_parity(x)
#define  numOfOnes(x)        __builtin_popcount(x)
#define  numOfZeroAtEnd(x)   __builtin_ctz(x)
#define  leaderZeros(x)      __builtin_clz(x)
#define  isPowerOfTwo(x)     (x && !(x & (x - 1)))
#define  lsb(x)              (x&-x)
#define  ExTime              cout << "My Time : " << (double)clock()/CLOCKS_PER_SEC << " ms" << endl;

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

typedef tree < int, null_type, less <int>, rb_tree_tag, tree_order_statistics_node_update>  indexed_set;
typedef long long            ll;
typedef long double          ld;
typedef unsigned int         uint;
typedef unsigned long long   ull;
typedef tuple <int,int,int>  tupl;
typedef complex <ld>         coplx;

int Dx8[8] = { 1, -1, 0, 0, 1, 1, -1, -1 }, Dx4[4] = { 0, 0, 1,-1};
int Dy8[8] = { 0, 0, 1, -1, 1, -1, 1, -1 }, Dy4[4] = { 1,-1, 0, 0};

ll gcd(ll a, ll b) { return a % b ? gcd(b, a % b) : b; }
int random (int i) { return rand() % i; }
void fast() { cin.sync_with_stdio(0); cin.tie(0); cout.tie(0); }

#ifdef Counting_sort
int frCs[10000001];

void counting_sort(int arr[], int mx, int n)
{
    int _r  = 0; rep(i, 0, n) ++frCs[arr[i]];
    rep(i, 0, mx + 1) while(frCs[i]) arr[_r++] = i, --frCs[i]; return;
}
#endif

bool com(pair <int, bool> a, pair <int, bool> b)
{
    if(a.F > b.F)                    return true;
    else if(a.F == b.F && a.S > b.S) return true;
    else                             return false;
};

class comp
{
public :
    bool operator () (tupl a, tupl b)
    {
        if(get <0> (a) > get <0> (b))         return true;
        else if(get <0> (a) == get <0> (b) && (get <1> (a) != get <1> (b)))  return (get <1> (a) > get <1> (b));
        else if(get <0> (a) == get <0> (b) && (get <2> (a) != get <2> (b)))  return (get <2> (a) > get <2> (b));
        else                                  return false;
    }
};

struct str
{
    int v1, v2, v3;
    bool operator < (str other) const
    {
        if(v1 < other.v1)                         return true;
        else if(v1 == other.v1 && v2 != other.v2) return v2 < other.v2;
        else if(v1 == other.v1 && v3 != other.v3) return v3 < other.v3;
        else                                      return false;
    }
};

const double      inf        = 1.0 / 0.0;
const double      pi         = 2 * acos(0.0);
const double      error      = 1e-9;
const long long   ooo        = (ll)2e18;
const int         MOD        = (int)1e9 + 7;
const int         oo         = 0x3f3f3f3f;
const int         MxsZ       = (int)4e5 + 6;

/**----------------------->>  Template  <<------------------------*/

int q, n, a[405], l, r,area, a1, a2, b1, b2;
bool ok;

/**------------------>>  Initialization gap  <<-------------------*/

int main()
{
    Hello_Friend

    cin >> q;
    while(q--)
    {
        cin >> n; n *= 4; read(a, 0, n); ok = true;
        sort(a, a + n);  l = 0, r = n - 1, area = -1;

        while (l <= r && ok)
        {
            a1 = a[l++], a2 = a[l++], b1 = a[r--], b2 = a[r--];

            if (a1 == a2 && b1 == b2 && (area == -1 || area == a1 * b1)) area = a1 * b1;
            else ok = false;
        }
        puts(ok ? "YES\n": "NO\n");
    }
}
