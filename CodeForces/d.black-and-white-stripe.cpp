// https://codeforces.com/contest/1690/problem/D

#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <locale>
#include <sys/types.h>
#include <vector>
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

#define endl '\n'
#define READ(a, n)                                                      \
  for (int i = 0; i < n; cin >> a[i++])                                 \
    ;

#define DEBUG(args...)                                                  \
  {                                                                     \
    string _s = #args;                                                  \
    replace(_s.begin(), _s.end(), ',', ' ');                            \
    stringstream _ss(_s);                                               \
    istream_iterator<string> _it(_ss);                                  \
    err(_it, args);                                                     \
  }

using namespace std;

using i128 = __int128_t;
using i64 = int64_t;
using i32 = int32_t;

using u128 = __uint128_t;
using u64 = uint64_t;
using u32 = uint32_t;
using ld = long double;
template <class T> using matrix = vector<vector<T>>;

const int N = 1e5 + 9, M = 3e7 + 9, oo = 0x3f3f3f3f, MOD = 1e9 + 7;
const ld EPS = 1e-12;

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
  freopen("cros.in", "r", stdin);
  // freopen("output.out", "w", stdout);
}

long double calc(long double x, long double y) {
  return sqrt(x * x + y * y);
}

i64 n, k;
string s;

void Solve() {
  cin >> n >> k >> s;

  int l = 0, r = k - 1, minWhite = oo, curWhiteInSegment = 0;
  for (int i = 0; i < k; ++i) {
    if (s[i] == 'W')
      curWhiteInSegment++;
  }

  minWhite = min(minWhite, curWhiteInSegment);
  while (r + 1 < n) {
    if (s[l] == 'W')
      curWhiteInSegment--;
    if (s[r + 1] == 'W')
      curWhiteInSegment++;
    l++, r++;

    minWhite = min(minWhite, curWhiteInSegment);
  }

  cout << minWhite << endl;
}

int main() {
  fast();
  //  file();

  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    Solve();
  }
}
