// https://codeforces.com/contest/1551/problem/B1

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

i32 n, k, a[N], to_color, c[N], cnt[N];
set <int> color[N];
set <pair <int, int>> prio;

void _clear() {
  prio.clear();
  for(int i = 0; i < n; ++i) {
    c[i] = 0;
    color[a[i]].clear();
    cnt[a[i]] = 0;
  }
}

string s;
i32 cnt_letr[26], res, ons;

void Solve() {
  cin >> s;
  for(int i = 0; i < (i32)s.size(); ++i) cnt_letr[s[i] - 'a']++;
  for(int i = 0; i < 26; ++i) {
    if(cnt_letr[i] > 1) res++;
  }
  for(int i = 0; i < 26; ++i) {
    if(cnt_letr[i] == 1) ons++;
  }
  res += ons / 2;
  cout << res << endl;
  for(int i = 0; i < 26; ++i)
    cnt_letr[i] = 0;
  res = ons = 0;
  return;
  
  cin >> n >> k;
  
  for(int i = 0; i < n; ++i) {
    cin >> a[i];
    cnt[a[i]]++;
  }

  for(int i = 1; i <= k; ++i) {
    prio.insert({0, i});
  }

  to_color = (n / k) * k;
  for(int i = 0; i < n && to_color > 0; ++i) {
    set <pair <int, int>>::iterator cur_color = prio.begin();
    while(cur_color != prio.end() && (color[a[i]].count(cur_color->second) || cur_color->first >= (n / k) || cnt[a[i]] == 1)) {
      cur_color++;
    }

    if(cur_color != prio.end()) {
      --to_color;
      color[a[i]].insert(cur_color->second);
      prio.insert({cur_color->first + 1, cur_color->second});
      c[i] = cur_color->second;
      prio.erase(cur_color);
    }
  }

  for(int i = 0; i < n && to_color > 0; ++i) if(cnt[a[i]] == 1) {
    set <pair <int, int>>::iterator cur_color = prio.begin();
    while(cur_color != prio.end() && cur_color->first >= (n / k)) {
      cur_color++;
    }

    if(cur_color != prio.end()) {
      --to_color;
      color[a[i]].insert(cur_color->second);
      prio.insert({cur_color->first + 1, cur_color->second});
      c[i] = cur_color->second;
      prio.erase(cur_color);
    }
  }

    
  for(int i = 0; i < n; ++i) cout << c[i] << " \n"[i == n - 1];
  _clear();
}

int main() { 
  fast();
  // file();
  
  int t = 1; cin >> t;
  for(int i = 1; i <= t; ++i) {
    Solve();
  }
}
