// https://codeforces.com/contest/1527/problem/B1

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

int n, match;
string s;
stack <int> mis_match;
bool alice_turn, is_palindrome, is_last_reverse;
i32 Alice, Bob;

void _clear() {
  mis_match = stack <int> ();
  alice_turn = true;
  is_last_reverse = false;
  is_palindrome = false;
  Alice = Bob = match = 0;
}

bool is_pal(string &x) {
  string y = x;
  reverse(y.begin(), y.end());
  return x == y;
}

void Solve() {
  _clear();
  
  cin >> n >> s;
  for(int i = 0; i < (n >> 1); ++i) {
    if(s[i] != s[n - i - 1]) {
      if(s[i] == '0')
	mis_match.push(i);
      else
	mis_match.push(n - i - 1);
    } else {
      if(s[i] == '0')
       ++match;
    }
  }
  
  is_palindrome = is_pal(s);
  // reverse is actually do nothing!
  if(is_palindrome) {
    if(n & 1) {
      if(s[n >> 1] == '0') {
	s[n >> 1] = '1';
	++Alice;
	alice_turn = false;
      }
    }
  }
  else {
    alice_turn = false;
    is_last_reverse = true;
  }
  
  while(!mis_match.empty()) {
    if(alice_turn) {
      if(is_last_reverse) {
	i32 inx = mis_match.top();
	mis_match.pop();
	s[inx] = '1';
	++Alice;
	is_last_reverse = false;
      } else {
	is_last_reverse = true;	
      }
      alice_turn = false;
    } else {
      if(is_last_reverse) {
	i32 inx = mis_match.top();
	mis_match.pop();
	s[inx] = '1';
	++Bob;
	is_last_reverse = false;
      } else {
	is_last_reverse = true;	
      }      
      alice_turn = true;
    }
  }
  
  match += match;
  if(match) {
    if(match & 1) {
      if(alice_turn) {
	++Bob;
      } else {
	++Alice;
      }
    } else {
      if(alice_turn) {
	Alice += 2;
      } else {
	Bob += 2;
      }
    }
  }
  
  cout << (Alice < Bob ? "ALICE" : Alice > Bob ? "BOB" : "DRAW") << endl;
}

int main() { 
  fast();
  // file();

  int t = 1; cin >> t;
  for(int i = 1; i <= t; ++i) {
    Solve();
  }
}
