// https://codeforces.com/contest/224/problem/A

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

/** Author  : Abd El-Twab  M. Fakhry
*   Created : 00:00 PM :: 00/07/2019
*/

#define  bt(i)              (1LL << (i))
#define  eq(x, y)           (fabs((x)-(y)) <= error)
#define  endl                '\n'
#define  rep(i, l, r)        for (int i = l; i < r; i++)
#define  repr(i, r, l)       for (int i = r; i > l; i--)
#define  DO_NOT_GIVE_UP      fast();
#define  all(a)              a.begin() , a.end()
#define  NumberOfDigits(n)   ((int)log10(n) + 1)
#define  sz(a)               (int)a.size()
#define  precision(n)        cout << fixed << setprecision(n)
#define  debug(x)            cerr << #x << " = " << (x) << '\n'
#define  _CRT_SECURE_NO_WARNINGS
#define  RT(n)               return cout << (n) << endl, 0;
#define  F                   first
#define  S                   second
#define  PB                  push_back
#define  of(n)               find_by_order(n)
#define  position_of(n)      order_of_key(n)
#define  parityOfOnes(x)     __builtin_parity(x)
#define  numOfOnes(x)        __builtin_popcount(x)
#define  numOfZeroAtEnd(x)   __builtin_ctz(x)
#define  leaderZeros(x)      __builtin_clz(x)
#define  Unique(n)           (n).erase(unique(all(n)), (n).end())
#define  infinity            (1<<28)
#define  Time(n)             cerr << "My Time : " << fixed << setprecision(9) << (n) << " ms" << endl
#define  PQ(T)               priority_queue < T, vector <T> , greater <T> >

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

typedef tree < int, null_type, less <int>, rb_tree_tag, tree_order_statistics_node_update>  indexed_set;
typedef long long            ll;
typedef long double          ld;
typedef unsigned int         uint;
typedef unsigned long long   ull;
typedef tuple <int,int,int>  ltuple;
typedef complex <ld>         coplx;

int dx[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };
int dy[8] = { 0, 0, 1, -1, 1, -1, 1, -1 };

void fast()
{
    cin.tie(0),cout.tie();
    cin.sync_with_stdio(0);
}

bool com(int a, int b)
{
    if(abs(a) < abs(b))         return true;
    else if(abs(a) == abs(b))   return a < b;
    else                        return false;
};

class comp
{
public :
    bool operator () (ltuple a, ltuple b)
    {
        if(get <0> (a) > get <0> (b))         return true; /// > smallest at top
        else if(get <0> (a) == get <0> (b) && (get <1> (a) != get <1> (b)))       return (get <1> (a) > get <1> (b));
        else if(get <0> (a) == get <0> (b) && (get <2> (a) != get <2> (b)))       return (get <2> (a) > get <2> (b));
        else                                  return false;
    }
};

struct str
{
    int v1, v2, v3;
    bool operator < (str other) const
    {
        if(this->v1 < other.v1)               return true;
        else if(this->v1 == other.v1 && this->v2 != other.v2)      return this->v2 < other.v2;
        else if(this->v1 == other.v1 && this->v3 != other.v3)      return this->v3 < other.v3;
        else                                  return false;
    }
};

const long double oo         = 9e18;
const long double PI         = 3.141592653589793238L;
const long double error      = 1e-9;
const int         MxsZ       = (int)1e6+6;

/**----------------------->>  Template  <<------------------------*/

ll a, b, c, f, g, h;

int main()
{
    DO_NOT_GIVE_UP

    cin >> a >> b >> c;

    f = sqrt((a*c)/b); g = sqrt((a*b)/c); h = sqrt((c*b)/a);
    cout << 4*(f+g+h) << endl;
}
