// https://codeforces.com/contest/1542/problem/B

#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

#define endl '\n'

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

const int N = 200 + 9, M = N << 1, oo = 0x3f3f3f3f, Mod = 1e9 + 7; 
const ld eps = 1e-9;

void fast() {			
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
}

void file() {
  freopen("input.in", "r", stdin);
  freopen("output.out", "w", stdout);
}

i64 n, x, y;

void Solve() {
  cin >> n >> x >> y;

  i64 power_of_x = 1;
  bool yes = false;
  while(power_of_x <= n) {
    if((n - power_of_x) % y == 0) {
      yes = true;
      break;
    } else if(x == 1) {
      break;
    }
    power_of_x *= x;
  }

  cout << (yes ? "YES" : "NO") << endl;
}

int main() { 
  fast();
  // file();

  int t = 1; cin >> t;
  for(int i = 1; i <= t; ++i) {
    Solve();
  }
}
