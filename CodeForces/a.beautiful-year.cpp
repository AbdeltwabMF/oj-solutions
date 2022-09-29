// https://codeforces.com/contest/271/problem/A

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

bool check_distinct(vector <i32> const &x) {
  vector <i32> v = x;
  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());
  return v.size() >= 4;
}

i32 n;

void Solve() {
  cin >> n;
  for(int i = n + 1; true; ++i) {
    if(check_distinct({i % 10, i % 100 / 10, i % 1000 / 100, i % 10000 / 1000})) {
      cout << i << endl;
      return;
    }
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
