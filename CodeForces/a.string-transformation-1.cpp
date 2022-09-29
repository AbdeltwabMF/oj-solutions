// https://codeforces.com/contest/1383/problem/A

#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

#define endl '\n'
#define read(n, a)  for(int i = 0; i < n; cin >> a[i++]);

using namespace std;

typedef long long ll;

const int N = 1e5 + 9, M = N << 1, oo = 0x3f3f3f3f, Mod = 1e9 + 7; 

void fast() {			
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
}

class DSU {
public:
  vector <int> _parent, _size;
  size_t _n;
  
  DSU() = default;
  DSU(int n) {
    _parent.assign(n + 1, -1);
    _size.assign(n + 1, 1);
    _n = n;
  }

  int find(int x) {
    if(_parent[x] == -1)
      return x;
    return _parent[x] = find(_parent[x]);
  }

  bool _union(int u, int v) {
    int pu = find(u);
    int pv = find(v);
    if(pu == pv)
      return false;

    if(_size[pv] > _size[pu])
      swap(pu, pv);

    _parent[pv] = pu;
    _size[pu] += _size[pv];
    return true;
  }
};

int n;
char a[N], b[N];

void Solve() {
  cin >> n;
  for(int i = 0; i < n; ++i) cin >> a[i];
  for(int i = 0; i < n; ++i) cin >> b[i];

  int ans = 0;
  DSU dsu(26);
  for(int i = 0; i < n; ++i) {
    if(a[i] > b[i]) {
      cout << -1 << endl;
      return;
    }
    if(dsu._union(a[i] - 'a', b[i] - 'a'))
      ++ans;
  }
  cout << ans << endl;
}

int main() { 
  fast();
  
  int t = 1; cin >> t;
  for(int i = 1; i <= t; ++i) {
    Solve();
  }
}
