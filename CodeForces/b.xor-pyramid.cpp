// https://codeforces.com/contest/983/problem/B

#include <algorithm>
#include <functional>
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

#define endl        '\n'
#define read(a, n)  for (int i = 0; i < n; cin >> a[i++]);

#define debug(args...)				\
  {						\
    string _s = #args;				\
    replace(_s.begin(), _s.end(), ',', ' ');	\
    stringstream _ss(_s);			\
    istream_iterator<string> _it(_ss);		\
    err(_it, args);				\
  }

using namespace std;

using i128 = __int128_t;
using i64 = int64_t;
using i32 = int32_t;

using u128 = __uint128_t;
using u64 = uint64_t;
using u32 = uint32_t;
using ld = long double;

const int N = 2e5 + 9, M = N << 1, oo = 0x3f3f3f3f, Mod = 1e9 + 7;
const ld eps = 1e-9;
const i64 INF = 0x3f3f3f3f3f3f3f3f;

void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << endl;
  err(++it, args...);
}

void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
}

void file() {
  // freopen("input.in", "r", stdin);
  freopen("output.out", "w", stdout);
}

int n, q, a[5005], l, r;
u32 xor_table[5005][5005], dp[5005][5005];

void Solve() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    xor_table[0][i] = dp[0][i] = a[i];
  }

  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < n - i; ++j) {
      xor_table[i][j] = (xor_table[i - 1][j] ^ xor_table[i - 1][j + 1]);
      dp[i][j] = max({xor_table[i][j], dp[i - 1][j], dp[i - 1][j + 1]});
    }
  }

  cin >> q;
  while (q--) {
    cin >> l >> r;
    cout << dp[r - l][l - 1] << endl;
  }
}

int main() {
  fast();
  // file();

  int t = 1; // cin >> t;
  for (int i = 1; i <= t; ++i) {
    Solve();
  }
}
