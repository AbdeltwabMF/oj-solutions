// https://codeforces.com/contest/1729/problem/B

#include <unordered_map>
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

#define endl '\n'
#define READ(a, n) for (int i = 0; i < n; cin >> a[i++]);

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

const int N = 5e5 + 5, M = 2e6 + 6, oo = 0x3f3f3f3f, MOD = 1e9 + 7;
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
  freopen("input.in", "r", stdin);
  freopen("output.out", "w", stdout);
}

int n;
string t;
unordered_map<int, char> charset;

void Solve() {
  cin >> n >> t;
  for (int i = 1; i <= 26; ++i) {
    charset[i] = char('a' + i - 1);
  }
  string ans = "";
  for(int i = n - 1; i >= 0; --i) {
    if(t[i] != '0') {
      ans += charset[t[i] - '0'];
    } else {
      ans += charset[(t[i - 1] - '0') + (t[i - 2] - '0') * 10];
      i -= 2;
    }
  }
  reverse(begin(ans), end(ans));
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
