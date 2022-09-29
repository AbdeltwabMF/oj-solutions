// https://codeforces.com/contest/143/problem/A

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

/** Author  : Abd El-Twab  M. Fakhry
*   Created : 09:53 PM :: 27/06/2019
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

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

double distanceBetweenTwoPoints(double x, double y, double a, double b)
{
    return sqrt((x - a)*(x - a) + (y - b)*(y - b));
}

bool isPrime(int n)
{
    if(n == 2)
        return true;
    if((n < 2) || !(n%2))
        return false;
    for(int i = 3; i*i <= n; i+=2)
        if(!(n%i))
            return false;
    return true;
}

void fast()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
}

/**---------------------------->>  Template  <<-----------------------------*/

set <int> baby;
set <int> ans;

int main()
{
    DO_NOT_GIVE_UP
    int r1, r2, c1, c2, d1, d2;
    cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;
    baby.insert(r1);
    baby.insert(r2);
    baby.insert(c1);
    baby.insert(c2);
    baby.insert(d1);
    baby.insert(d2);

    rep(i, 1, 21)
    rep(j, 1, 21)
    rep(k, 1, 21)
    rep(l, 1, 21)
    if(i+l == d1 && i+j == r1 && i+k == c1 && k+l == r2 && j+l == c2 && k+j == d2 && sz(baby) + (d1 == d2) + (r1 == r2) + (c1 == c2) == 6)
    {
        ans.insert(i);
        ans.insert(j);
        ans.insert(k);
        ans.insert(l);

        if(*ans.rbegin() < 10)
            return cout << i << " " << j << endl << k << " " << l, 0;
    }
    cout << "-1";
}
