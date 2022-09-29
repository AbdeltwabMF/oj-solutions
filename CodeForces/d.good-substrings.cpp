// https://codeforces.com/contest/271/problem/D

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

vector <i64> p_pow(1505);

void calc_pow(i32 p) {
  p_pow[0] = 1;
  for(int i = 1; i < 1500; ++i) {
    p_pow[i] = p_pow[i - 1] * p % Mod;
  }
}

i32 str_hashed_1[1505], str_hashed_2[1505];

void calc_hash(string const &str, i32 p, i32 _hash_[]) {
  calc_pow(p);
  i32 n = (i32)str.size();
  for(int i = 0; i < n; ++i) {
    _hash_[i + 1] = (_hash_[i] + (str[i] - '0' + 1) * p_pow[i]) % Mod;
  }
}

i64 bin_exp(i64 a, i64 b, i64 m = Mod) {
  i64 res;
  for(res = 1; b; b >>= 1) {
    if(b & 1ll) {
      res = res * a % m;
    }
    a = a * a % m;
  }
  return res;
}

i64 mod_inv(i64 a, i64 b) {
  return bin_exp(a, b - 2, b);
}

string str, pat;
i32 x, ans;

void Solve() {
  cin >> str >> pat >> x;
  calc_hash(str, 67, str_hashed_1);
  calc_hash(str, 97, str_hashed_2);

  vector < pair<i32, i32> > g;
  i32 n = (i32)str.size();

  for(int i = 0; i < n; ++i) {
    i32 bad = 0;
    string sub = "";
    for(int j = i; j < n; ++j) {
      sub += str[j];
      if(pat[str[j] - 'a'] == '0') {
        ++bad;
      }
      if(bad <= x) {
        g.emplace_back((str_hashed_1[j + 1] + Mod - str_hashed_1[i]) % Mod * mod_inv(bin_exp(67, i), Mod) % Mod,
                       (str_hashed_2[j + 1] + Mod - str_hashed_2[i]) % Mod * mod_inv(bin_exp(97, i), Mod) % Mod);
      }
    }
  }

  sort(g.begin(), g.end());
  g.resize(unique(g.begin(), g.end()) - g.begin());
  cout << g.size() << endl;
}

int main() {
  fast();
  // file();

  int t = 1; // cin >> t;
  for (int i = 1; i <= t; ++i) {
    Solve();
  }
}
