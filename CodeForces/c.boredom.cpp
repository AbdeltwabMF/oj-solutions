// https://codeforces.com/contest/456/problem/C

#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef long long ll;

const int N = 2e5 + 9, M = N << 1, oo = 0x3f3f3f3f, Mod = 1e9 + 7; 

void fast() {			
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
}

ll n, cnt[N], dp[N], take, leave, a;

void Solve() {
  cin >> n;
  for(int i = 0; i < n; ++i) {
    cin >> a; ++cnt[a];
  }

  dp[1] = cnt[1];
  for(int i = 2; i <= 100000; ++i) {
    dp[i] = max(dp[i - 2] + i * cnt[i], dp[i - 1]);
  }
  cout << dp[100000] << endl;
}

int main() { 
  fast();
  
  int t = 1;
  for(int i = 1; i <= t; ++i) {
    Solve();
  }
}
