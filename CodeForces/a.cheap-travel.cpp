// https://codeforces.com/contest/466/problem/A

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

/** Author  : Abd El-Twab  M. Fakhry
*   Created : 07:18 PM :: 13/07/2019
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

int gcd(int a, int b);
double distanceBetweenTwoPoints(double x, double y, double a, double b);
bool isPrime(int n);

void fast()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
}

/**---------------------------->>  Template  <<-----------------------------*/

ll n, m, a, b;

int main()
{
    DO_NOT_GIVE_UP

    cin >> n >> m >> a >> b;

    if((double)b/m > a)
        return cout << n * a << endl, 0;

    if(m > n && n*a > b)
        return cout << b << endl, 0;

    if((n%m) * a > (n%m) * b)
        cout << (n/m) * b + b << endl;
    else
        cout << (n/m) * b + (n%m) * a << endl;
}
