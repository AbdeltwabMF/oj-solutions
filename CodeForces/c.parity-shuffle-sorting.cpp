// https://codeforces.com/contest/1733/problem/C

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

int n, a[N];

void Solve() {
  cin >> n;
  READ(a, n);

  vector<pair<int, int>> pairsOfIndx;
  if(n > 1 && (a[0] & 1) != (a[n - 1] & 1)) {
    pairsOfIndx.push_back({1, n});
    a[n - 1] = a[0];
  } else if(n > 1){
    pairsOfIndx.push_back({1, n});
    a[0] = a[n - 1];
  }

  for(int i = n - 2; i > 0; --i) {
    if((a[i] & 1) == (a[n - 1] & 1)) {
      a[i] = a[n - 1];
      pairsOfIndx.push_back({i + 1, n});
    }
  }
  for(int i = 1; i + 1 < n; ++i) {
    if((a[i] & 1) != (a[n - 1] & 1)) {
      a[i] = a[0];
      pairsOfIndx.push_back({1, i + 1});
    }
  }

  cout << pairsOfIndx.size() << endl;
  for(auto i : pairsOfIndx)
    cout << i.first << " " << i.second << endl;
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
