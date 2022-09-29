// https://codeforces.com/contest/1527/problem/B2

#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

#define endl '\n'
#define read(a, n)  for(int i = 0; i < n; cin >> a[i++]);

using namespace std;

using i128 = __int128_t;
using i64 = int64_t;
using i32 = int32_t;
using i16 = int16_t;
using i8 = int8_t;

using u128 = __uint128_t;
using u64 = uint64_t;
using u32 = uint32_t;
using u16 = uint16_t;
using u8 = uint8_t;
using ld = long double;

const int N = 2e5 + 9, M = N << 1, oo = 0x3f3f3f3f, Mod = 1e9 + 7; 
const ld eps = 1e-9;

void fast() {			
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
}

void file() {
  freopen("input.in", "r", stdin);
  freopen("output.out", "w", stdout);
}

int n;
string s;

bool is_pal(string &x) {
  string y = x;
  reverse(y.begin(), y.end());
  return x == y;
}

void Solve() {
  cin >> n >> s;
  int z = count(s.begin(), s.end(), '0'), o = 0;
  for(int i = 0; i < (n >> 1); ++i) {
    if((s[i] == '1' || s[n - i - 1]) && s[i] != s[n - i - 1]) {
      ++o;
    }
  }
  if(is_pal(s)) {
    if(z == 1) {
      cout << "BOB" << endl;
      return;
    } else if(z % 2) {
      cout << "ALICE" << endl;
      return;
    }
    cout << "BOB" << endl;
    return;
  }
  if(o == 1 && z == 2) {
    cout << "DRAW" << endl;
    return;
  }
  
  cout << "ALICE" << endl;
}

int main() { 
  fast();
  // file();

  int t = 1; cin >> t;
  for(int i = 1; i <= t; ++i) {
    Solve();
  }
}
