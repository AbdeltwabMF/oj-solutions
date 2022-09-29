// https://codeforces.com/contest/948/problem/B

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

int mostPrime[N];
int Primes[664580], pnx;

void linear_sieve(int x) {
    for (int i = 2; i <= x; ++i) {
        if (mostPrime[i] == 0) {
            mostPrime[i] = Primes[pnx++] = i;
        }
        for (int j = 0, comp, lp = mostPrime[i]; j < pnx && Primes[j] <= lp && (comp = i * Primes[j]) <= x; ++j) {
            mostPrime[comp] = lp;
        }
    }
}

int n, k, a;

int main() {
    Fast();

    cin >> n;
    linear_sieve(n);
    int ans = oo;

    for (int i = n - mostPrime[n] + 1; i <= n; ++i) {
        ans = min(ans, i - (mostPrime[i] == i ? 0 : mostPrime[i]) + 1);
    }
    cout << ans << endl;
}