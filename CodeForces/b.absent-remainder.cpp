// https://codeforces.com/contest/1613/problem/B

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

i64 bin_exp(i64 a, i64 p) {
  i64 res;
  for(res = 1; p; p >>= 1) {
    if(p & 1)
      res = res * a;
    a = a * a;
  }
  return res;
}

i32 n, a[N], mn, half;


void Solve() {
  cin >> n;
  half = n >> 1;
  mn = oo;

  for(int i = 0; i < n; ++i) {
    cin >> a[i];
    if(a[i] < mn)
      mn = a[i];
  }

  for(int i = 0, j = 0; j < half; ++i, ++j) {
    cout << (a[i] != mn ? a[i] : a[++i]) << " " << mn << endl;
  }
}

int main() {
  fast();
  // file();

  int t = 1; cin >> t;
  for (int i = 1; i <= t; ++i) {
    Solve();
  }
}