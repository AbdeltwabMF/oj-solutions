// https://codeforces.com/contest/988/problem/B

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
#define  print(arr, l, r)    for(int i = (l); i < (r); cout << arr[i++] << "\n")
#define  rep(i, l, r)        for (int i = l; i < r; i++)
#define  repr(i, r, l)       for (int i = r; i > l; i--)
#define  PQ(T)               priority_queue < T, vector <T> , greater <T> >
#define  Unique(n)           (n).erase(unique(all(n)), (n).end())
#define  endl                '\n'
#define  Hello_Friend        fast();
#define  all(a)              a.begin() , a.end()
#define  NumberOfDigits(n)   ((int)log10(n) + 1)
#define  sz(a)               (int)a.size()
#define  debug(x)            cout << #x << " = " << (x) << '\n'
#define  RT(n)               return cout << (n) << endl, 0;
#define  F                   first
#define  S                   second
#define  PB                  push_back
#define  EB                  emplace_back
#define  of(n)               find_by_order(n)
#define  position_of(n)      order_of_key(n)
#define  isPowerOfTwo(x)     (x && !(x & (x - 1)))

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

typedef tree < int, null_type, less <int>, rb_tree_tag, tree_order_statistics_node_update>  indexed_set;
typedef long long            ll;
typedef unsigned int         uint;
typedef unsigned long long   ull;

int Dx8[8] = { 1, -1, 0, 0, 1, 1, -1, -1 }, Dx4[4] = { 0, 0, 1,-1};
int Dy8[8] = { 0, 0, 1, -1, 1, -1, 1, -1 }, Dy4[4] = { 1,-1, 0, 0};

ll gcd(ll a, ll b)     { return a % b ? gcd(b, a % b) : b; }
ll lcm(ll a, ll b)     { return a * b / gcd(a, b); }
int random (int i)     { return rand() % i; }
void fast()            { cin.sync_with_stdio(0); cin.tie(0); cout.tie(0); }

const double inf  = 1.0 / 0.0,      pi  = 2 * acos(0.0),   error = 1e-9;
const int    MxsZ = (int)1e7 + 6,   MOD = (int)1e9 + 7,       oo = 0x3f3f3f3f;

bool com(string a, string b){ return sz(a) > sz(b); }

/**----------------------->>  Template  <<------------------------*/

int n;
string arr[109];

/**------------------>>  Initialization gap  <<-------------------*/

int main()
{
    Hello_Friend

    cin >> n; read(arr, 0, n); sort(arr,arr+n, com);
    rep(i, 0, n-1)
        if(arr[i].find(arr[i+1]) == -1) RT("NO"); reverse(arr, arr+n);

    cout << "YES" << endl; print(arr, 0, n);
}
