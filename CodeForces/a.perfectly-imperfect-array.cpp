// https://codeforces.com/contest/1514/problem/A

#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

#define endl '\n'
#define read(a, n)  for(int i = 0; i < n; cin >> a[i++]);

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int N = 1e6 + 9, M = N << 1, oo = 0x3f3f3f3f, Mod = 1e9 + 7; 
const ld eps = 1e-9;

void fast() {			
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
}

int n, a[N];

void Solve() {
  cin >> n;
  read(a, n);
  
  for(int i = 0; i < n; ++i) {
    if((int)sqrt(a[i]) * (int)sqrt(a[i]) != a[i]) {
      cout << "YES" << endl;
      return;
    }
  }
  cout << "NO" << endl;
}

int main() { 
  fast();
  
  int t = 1; cin >> t;
  for(int i = 1; i <= t; ++i) {
    Solve();
  }
}
