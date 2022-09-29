// https://codeforces.com/contest/1285/problem/D

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

class Trie {
  struct Node {
    Node* ch[2];

    Node() {
      memset(ch, 0, sizeof ch);
    }

    ~Node() {
      for(Node* &child : ch)
	delete child;
    }
  };
  
public:
  Node* root;

  Trie() {
    root = new Node();
  }

  ~Trie() {
    delete root;
  }

  void insert(int x) {
    Node* cur = root;
    int inx;
    for(int i = 30; i >= 0; --i) {
      inx = (x >> i) & 1; // is it on?
      Node* &Next = cur->ch[inx];
      if(Next == nullptr) {
	Next = new Node;
      }
      cur = Next;
    }
  }

  int dfs(Node* node, int d) {
    if(!node->ch[0] && !node->ch[1])
      return 0;

    if(node->ch[0] && node->ch[1]) {
      return min(dfs(node->ch[0], d - 1), dfs(node->ch[1], d - 1)) | (1 << d);
    }

    if(node->ch[0]) {
      return dfs(node->ch[0], d - 1);
    } else {
      return dfs(node->ch[1], d - 1);
    }
  }
};

int n, a[N];

void Solve() {
  cin >> n;
  Trie* trie = new Trie();
  
  for(int i = 0; i < n; ++i) {
    cin >> a[i];
    trie->insert(a[i]);
  }
  
  cout << trie->dfs(trie->root, 30)  << endl;
}

int main() { 
  fast();
  
  int t = 1;
  for(int i = 1; i <= t; ++i) {
    Solve();
  }
}
