// https://codeforces.com/contest/271/problem/B

#include <bits/stdc++.h>

#define endl '\n'
#define debug(args...)                          \
  {                                             \
    string _s = #args;                          \
    replace(_s.begin(), _s.end(), ',', ' ');    \
    stringstream _ss(_s);                       \
    istream_iterator<string> _it(_ss);          \
    err(_it, args);                             \
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
const ld eps = 1e-18;
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
  freopen("input.in", "r", stdin);
  freopen("output.out", "w", stdout);
}

i32 lp[1000009], inx, primes[78555];

void linear_sieve(i32 x) {
  for(int i = 2; i <= x; ++i) {
    if(lp[i] == 0) {
      primes[inx++] = i;
      lp[i] = i;
    }
    for(int j = 0; j < inx && primes[j] <= i && i * primes[j] <= x; ++j) {
      lp[i * primes[j]] = primes[j];
    }
  }
}

i32 n, m, a[505][505], cost[505][505];

void Solve() {
  cin >> n >> m;
  linear_sieve(1000000);

  for(int i = 0; i < n; ++i)
    for(int j = 0; j < m; ++j)
      cin >> a[i][j];

  for(int i = 0; i < n; ++i)
    for(int j = 0; j < m; ++j)
      cost[i][j] = primes[lower_bound(primes, primes + inx, a[i][j]) - primes] - a[i][j];

  i64 ans = INF;
  for(int i = 0; i < n; ++i) {
    i64 cur = 0;
    for(int j = 0; j < m; ++j) {
      cur += cost[i][j];
    }
    if(cur < ans)
      ans = cur;
  }

  for(int i = 0; i < m; ++i) {
    i64 cur = 0;
    for(int j = 0; j < n; ++j) {
      cur += cost[j][i];
    }
    if(cur < ans)
      ans = cur;
  }

  cout << ans << endl;
}

int main() {
  fast();
  // file();

  int t = 1; // cin >> t;
  for (int i = 1; i <= t; ++i) {
    Solve();
  }
}
