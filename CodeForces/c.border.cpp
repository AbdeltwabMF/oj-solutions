// https://codeforces.com/contest/1010/problem/C

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

int n, k, a;

int main() {
    Fast();

    cin >> n >> k;
    ll g = k;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        g = gcd(g, a);
    }
    cout << k / g << endl;
    for (int i = 0; i < k; i += g) {
        cout << i << " \n"[i == k];
    }
}