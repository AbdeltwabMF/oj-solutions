// https://codeforces.com/contest/1542/problem/C

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

const i64 N = 2e5 + 9, M = 1e16 + 9, oo = 0x3f3f3f3f, Mod = 1e9 + 7; 
const ld eps = 1e-9;

void fast() {			
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
}

void file() {
  freopen("input.in", "r", stdin);
  freopen("output.out", "w", stdout);
}

i64 Gcd(i64 a, i64 b) {
  if(!a || !b)
    return a | b;
  
  u64 shift = __builtin_ctz(a | b);
  a >>= __builtin_ctz(a);

  do{
    b >>= __builtin_ctz(b);
    if (a > b)
      swap(a, b);
    b -= a;
  } while (b);
  return a << shift;
}

i64 Lcm(i64 a, i64 b) {
  return a / Gcd(a, b) * b;
}

i64 n, LCM[N], lcm_inx, ans;

void Solve() {
  cin >> n;
  ans = 0;
  for(int i = 0; i <= lcm_inx; ++i) {
    ans += n / LCM[i];
  }

  cout << ans % Mod << endl;
}

int main() { 
  fast();
  //file();
  
  LCM[0] = 1;
  for(int i = 1; LCM[lcm_inx] < M; ++i) {
    LCM[lcm_inx + 1] = Lcm(LCM[lcm_inx], i);
    lcm_inx++;
  }

  int t = 1; cin >> t;
  for(int i = 1; i <= t; ++i) {
    Solve();
  }
}