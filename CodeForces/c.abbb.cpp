// https://codeforces.com/contest/1428/problem/C

#pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define endl      '\n'

using namespace std;

typedef int64_t    ll;
typedef __int128 i128;

void Fast() {
    cin.sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

void File() {
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
}

const int N = 4e5 + 9, M = 1e4 + 9, oo = 0x3f3f3f3f;

const ll INF  = 0x3f3f3f3f3f3f3f3f;
const ll mINF = 0xc0c0c0c0c0c0c0c0;

const int dr [] = {-1, 0, 1, 0};
const int dc [] = {0, 1, 0, -1};

string s;
int n;
stack <int> st;

void Solve()
{
    cin >> s;
    n = s.size();
    st = stack <int> ();

    for(int i = 0; i < n; ++i)
        if(st.size() && s[i] == 'B') st.pop();
        else st.push(s[i]);

    cout << st.size() << endl;
}

int main()
{
    Fast();

    int tc = 1; cin >> tc;
    for(int i = 1; i <= tc; ++i)
        Solve();
}
