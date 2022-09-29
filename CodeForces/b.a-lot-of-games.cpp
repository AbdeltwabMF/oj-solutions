// https://codeforces.com/contest/455/problem/B

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

void file() {
  freopen("input.in", "r", stdin);
}

class Trie {
public:
  Trie* ch[26];
  bool isEOW, Win, Lose;

  Trie() {
    memset(ch, 0, sizeof ch);
    isEOW = Win = Lose = false;
  }

  void insert(char* str) {
    if(*str == '\0') {
      isEOW = true;
      return;
    }
    
    int inx = *str - 'a';
    if(ch[inx] == nullptr)
      ch[inx] = new Trie();

    ch[inx]->insert(str + 1);
  }

  void dfs(Trie* node)  {
    bool isLeaf = true;
    for(int i = 0; i < 26; ++i) if(node->ch[i] != nullptr) {
	dfs(node->ch[i]);
	node->Win |= (!node->ch[i]->Win);
	node->Lose |= (!node->ch[i]->Lose);
	isLeaf = false;
      }
    if(isLeaf) {
      node->Win = false;
      node->Lose = true;
    }
  }
};

ll n, k, m;
char s[100100];

void Solve() {
  cin >> n >> k;
  Trie* trie = new Trie();

  while(n--) {
    cin >> s;
    (*trie).insert(s);
  }

  trie->dfs(trie);
  
//  cout << trie->Win << " " << trie->Lose << endl;

  if(trie->Win && trie->Lose) {
    cout << "First" << endl;
  } else if(trie->Win) {
    cout << (k & 1 ? "First" : "Second") << endl;
  } else {
    cout << "Second" << endl;
  }
}

int main() { 
  fast();
  
  int t = 1;
  // cin >> t;
  
  for(int i = 1; i <= t; ++i) {
    Solve();
  }
}
