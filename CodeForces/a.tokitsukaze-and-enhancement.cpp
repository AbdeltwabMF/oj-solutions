// https://codeforces.com/contest/1191/problem/A

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

/** Author  : Abd El-Twab  M. Fakhry
*   Created : 00:00 PM :: 00/00/2019
*           DO NOT GIVE UP
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
#define  debug(x)            cerr << #x << " = " << (x) << '\n';

using namespace std;
using namespace __gnu_pbds;

typedef long long            ll;
typedef long double          ld;
typedef unsigned int         uint;
typedef unsigned long long   ull;

const long double N          = 1e18;
const long double PI         = 3.141592653589793238L;
const long double error      = 1e-8;

void fast()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
}

int gcd(int a, int b);
bool isPrime(int n);
bool cmp(int i, int j);

struct str
{
    int distance, coins, indx;
    bool operator< (str other) const
    {
        return 1;
    }
};

/**---------------------------->>  Template  <<-----------------------------*/

int n;

int main()
{
    DO_NOT_GIVE_UP

    cin >> n;

    if(n%4 == 1)
        cout << "0 A" << endl;
    else if(n%4 == 2)
        cout << "1 B" << endl;
    else if(n%4 == 3)
        cout << "2 A" << endl;
    else if(n%4 == 0)
        cout << "1 A" << endl;


}
