// https://codeforces.com/contest/1189/problem/B

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

int main()
{
    DO_NOT_GIVE_UP

    int n;
    ll ans = 0;
    cin >> n;

    ll arr[n];
    rep(i, 0, n) cin >> arr[i];

    sort(arr,arr+n);
    reverse(arr,arr+n-2);

    rep(i, 0, n)
    {
        if(!i && arr[i] < arr[i+1] + arr[n-1])
            ans++;
        else if(i == n-1)
        {
            if(arr[i] < arr[i-1] + arr[0])
                ans++;
        }
        else if(arr[i] < arr[i+1] + arr[i-1])
            ans++;
    }
    if(ans == n)
    {
        cout << "YES" << endl;
        rep(i, 0, n) cout << arr[i] << " ";
    }
    else
        cout << "NO" << endl;
}
