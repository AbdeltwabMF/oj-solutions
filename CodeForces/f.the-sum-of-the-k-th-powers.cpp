// https://codeforces.com/contest/622/problem/F

#include <bits/stdc++.h>

#define endl    '\n'

using namespace std;
using namespace __gnu_cxx;

typedef int64_t ll;

const ll N = 1e6 + 9, M = 1e6 + 9, Mod = 1e9 + 7, oo = 0x3f3f3f3f;
const long double EPS = 1e-9;

void add_self(int& x, int y) {
    if((x += y) >= Mod) x -= Mod;
}

void sub_self(int& x, int y) {
    if((x -= y) < 0)    x += Mod;
}

int add(int x, int y) {
    return add_self( x, y), x;
}

int sub(int x, int y) {
    return sub_self( x, y), x;
}

int mul(int x, int y) {
    return (ll) x * y % Mod;
}

void mul_self(int& x, int y) {
    x = mul( x, y);
}

int neg(int x) {
    if(x < 0)   x += Mod;
    return x;
}

int fp(int x, int y) {
    if(!y)  return x > 0;
    if(y&1) return mul( x, fp( x, y - 1));
    return fp( mul( x, x), y >> 1);
}

int inv(int x) {
    return fp( x, Mod - 2);
}

void Fast() {
    cin.sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

void Solve()
{
    int n, k;
    cin >> n >> k;

    int m = k + 1;

    if(n <= m) {
        int Ans = 0;

        for(int i = 1; i <= n; i++) add_self( Ans, fp( i, k));
        cout << Ans << endl;
        return;
    }

    vector <int> Y;

    for(int x = 0, Sum = 0; x <= m; x++, add_self( Sum, fp( x, k))) Y.push_back(Sum);

    int Num = 1, Den = 1;

    for(int x = 0; x <= m; x++) mul_self( Num, sub( n, x));
    for(int x = 1; x <= m; x++) mul_self( Den, sub( 0, x));

    int Ans = 0;

    for(int x = 0; x <= m; x++) {
        int Cur = mul( Num, inv( sub( n, x)));

        add_self( Ans, mul( Y[x], mul( Cur, inv(Den))));

        if(x < m) {
            mul_self( Den, inv( sub( x, m)));
            mul_self( Den, add( x, 1));
        }
    }
    cout << Ans << endl;
}

int main()
{
    Fast();

    int tc = 1;
    for(int i = 1; i <= tc; ++i)
        Solve();
}

