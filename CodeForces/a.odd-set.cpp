// https://codeforces.com/contest/1542/problem/A

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

int n, a, odd, even;

void Solve() {
  cin >> n;
  odd = 0;
  even = 0;
  
  for(int i = 0; i < n << 1; ++i) {
    cin >> a;
    odd += a & 1;
    even += !(a & 1);
  }

  cout << (odd == even ? "YES" : "NO") << endl;
}

int main() { 
  fast();
  // file();

  int t = 1; cin >> t;
  for(int i = 1; i <= t; ++i) {
    Solve();
  }
}
