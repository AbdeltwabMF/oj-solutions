// https://codeforces.com/contest/1733/problem/B

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

int n, x, y;

void Solve() {
  cin >> n >> x >> y;
  if(x < y) swap(x, y);

  if(y || !x || (n - 1) % x != 0)  {
    cout << -1 << endl;
    return;
  }
  for(int i = 1; i <= n; ++i) {
    int cur = (n - i + 1 >= x) ? x : y;
    for(int j = 0; j < cur; ++j) {
      cout << i << " ";
    }
    i += i == 1 ? cur : cur ? cur - 1 : 0;
  }
  cout << endl;
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
