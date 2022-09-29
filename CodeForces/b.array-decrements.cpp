// https://codeforces.com/contest/1690/problem/B

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

i64 n, a[N], b[N];

void Solve() {
  cin >> n;
  i64 maxDifference = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
   }
   for (int i = 0; i < n; ++i) {
     cin >> b[i];
     maxDifference = max(a[i] - b[i], maxDifference);
   }

   for (int i = 0; i < n; ++i) {
     if (b[i]) {
       if (a[i] - b[i] < maxDifference) {
         cout << "NO" << endl;
         return;
       }
     }
   }

    cout << "YES" << endl;
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
