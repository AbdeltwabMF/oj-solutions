// https://codeforces.com/contest/1729/problem/D

#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

#define endl '\n'
#define READ(a, n) for (int i = 0; i < n; cin >> a[i++]);
#define PRINT(a, n) for (int i = 0; i < n; cout << a[i++] << " ");
#define DEBUG(args...)                                                  \
  {                                                                     \
    string _s = #args;                                                  \
    replace(_s.begin(), _s.end(), ',', ' ');                            \
    stringstream _ss(_s);                                               \
    istream_iterator<string> _it(_ss);                                  \
    err(_it, args);                                                     \
  }

using namespace std;

void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << endl;
  err(++it, args...);
}

using i128 = __int128_t;
using i64 = long long;
using i32 = int32_t;

using u128 = __uint128_t;
using u64 = uint64_t;
using u32 = uint32_t;
using ld = long double;
template <class T> using matrix = vector<vector<T>>;

const int N = 1e5 + 5, M = 2e6 + 6, oo = 0x3f3f3f3f, MOD = 1e9 + 7;
const ld EPS = 1e-12;

void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
}

void file() {
  freopen("input.in", "r", stdin);
  freopen("output.out", "w", stdout);
}

int n, x[N], y[N], z[N];

void Solve() {
  cin >> n;
  for(int i = 0; i < n; ++i) {
    cin >> x[i];
  }
  for(int i = 0; i < n; ++i) {
    cin >> y[i];
    z[i] = y[i] - x[i];
  }
  sort(z, z + n);

  int l = 0, r = n - 1;
  int ans = 0;
  while(l < r) {
    if(abs(z[l]) <= z[r]) {
      ++l, --r, ++ans;
    } else {
      ++l;
    }
  }
  cout << ans << endl;
}

int main() {
  fast();
  // file();

  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    // cout << "Case #" << i << ": ";
    Solve();
  }
}
