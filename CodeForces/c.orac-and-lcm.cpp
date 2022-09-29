// https://codeforces.com/contest/1350/problem/C

#pragma  GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef int64_t ll;
typedef uint64_t ull;
typedef __int128_t i128;
typedef __uint128_t ui128;
typedef long double ld;

void Fast() {
    std::istream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

const int N = 1e6 + 9, M = N << 1, oo = 0x3f3f3f3f, Mod = 1e9 + 7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const ld eps = 1e-9;

ll gcd(ll a, ll b) {
    if (!a)
        return b;

    int shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);

    while (b) {
        b >>= __builtin_ctz(b);
        if (a > b)
            swap(a, b);
        b -= a;
    }
    return a << shift;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

int leastPrime[N];
int Primes[664580], pnx;

void linear_sieve(int x) {
    for (int i = 2; i <= x; ++i) {
        if (leastPrime[i] == 0) {
            leastPrime[i] = Primes[pnx++] = i;
        }
        for (int j = 0, comp, lp = leastPrime[i]; j < pnx && Primes[j] <= lp && (comp = i * Primes[j]) <= x; ++j) {
            leastPrime[comp] = Primes[j];
        }
    }
}

int a[N];
ll sufGcd[N];
ll preLcm[N];
int n;

int main() {
    Fast();

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    sufGcd[n] = a[n];
    for (int i = n - 1; i >= 1; --i) {
        sufGcd[i] = gcd(a[i], sufGcd[i + 1]);
    }

    for (int i = 1; i < n; ++i) {
        preLcm[i] = lcm(a[i], sufGcd[i + 1]);
    }

    ll ans = 0;
    for (int i = 1; i < n; ++i) {
        ans = gcd(ans, preLcm[i]);
    }
    cout << ans << endl;
}