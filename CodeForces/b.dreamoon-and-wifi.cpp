// https://codeforces.com/contest/476/problem/B

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
#define  print(arr, l, r)    for(int i = (l); i < (r); cout << arr[i++] << " \n"[i == r])
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
#define  lsb(x)              (x & -x)

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

typedef tree < int, null_type, less <int>, rb_tree_tag, tree_order_statistics_node_update>  indexed_set;
typedef long long                 ll;
typedef unsigned int              uint;
typedef unsigned long long        ull;
typedef tuple <int, int, string>  tupl;

int Dx8[8] = { 1, -1, 0, 0, 1, 1, -1, -1 }, Dx4[4] = { 0, 0, 1,-1};
int Dy8[8] = { 0, 0, 1, -1, 1, -1, 1, -1 }, Dy4[4] = { 1,-1, 0, 0};

ll gcd(ll a, ll b)     { return a % b ? gcd(b, a % b) : b; }
ll lcm(ll a, ll b)     { return a * b / gcd(a, b); }
int random (int i)     { return rand() % i; }
void fast()            { cin.sync_with_stdio(0); cin.tie(0); cout.tie(0); }

const double inf  = 1.0 / 0.0,      pi  = 2 * acos(0.0),   error = 1e-9;
const int    MxsZ = (int)1e6 + 1,   mod = 1073741824,         oo = 0x3f3f3f3f;

/**----------------------->>  Template  <<------------------------*/

string s1, s2;
double idx, proba, ans;

/**------------------>>  Initialization gap  <<-------------------*/

int main()
{
    Hello_Friend  /** plus, minus, question mark */

    cout << fixed << setprecision(12);
    cin >> s1 >> s2; sort(all(s1)); sort(all(s2));

    rep(i, 0, sz(s1))   if(s1[i] == *begin(s2)) s2.erase(begin(s2)), s1[i] = '*'; sort(all(s1));

    while(!s1.empty() && *s1.begin() == '*') s1.erase(begin(s1));
    if(s2.empty()) RT(1.0);
    if(s2.find('-') != -1 || s2.find('+') != -1) RT(0.0);

    rep(i, 0, sz(s1)) (s1[i] == '-') ? idx-- : idx++;

    rep(i, 0, (1 << sz(s2)))
    {
        proba = 0;
        rep(j, 0, sz(s2)) if(i & (1 << j)) proba++; else proba--;
        if(proba  == idx) ans++;
    }
    cout << (ans / (1 << sz(s2))) << endl;
}
