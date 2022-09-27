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

const int N = 2e5 + 5, M = 4e5 + 6, oo = 0x3f3f3f3f, MOD = 1e9 + 7;
const ld EPS = 1e-12;

void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
}

void file() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "r", stdin);
  freopen("output.out", "w", stdout);
#endif
}

int c, coins[3], dp[770][160][110], remain;

int memo(int x, int y, int z) {
  if(x + y * 5 + z * 10 == remain) return 0; // all coke has been bought already
  int &res = dp[x][y][z];
  if(res) return res;
  res = oo;

  if(x >= 8)
    res = min(res, memo(x - 8, y, z) + 8);
  if(y >= 2)
    res = min(res, memo(x + 2, y - 2, z) + 2);
  if(z >= 1)
    res = min(res, memo(x + 2, y, z - 1) + 1);
  if(y >= 1 && x >= 3)
    res = min(res, memo(x - 3, y - 1, z) + 4);
  if(z >= 1 && x >= 3)
    res = min(res, memo(x - 3, y + 1, z - 1) + 4);
  return res;
}

void Solve() {
  cin >> c;
  memset(dp, 0, sizeof dp);
  remain = 0;
  for(int i = 0; i < 3; ++i)
    cin >> coins[i], remain += coins[i] * i * 5;
  remain = remain + coins[0] - c * 8;

  cout << memo(coins[0], coins[1], coins[2]) << endl;
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
