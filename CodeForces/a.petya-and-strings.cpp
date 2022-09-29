// https://codeforces.com/contest/112/problem/A

#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    
    for(int i = 0; i < (int)s1.size(); ++i)
        if(s1[i] < 97) s1[i] = char(s1[i] + 32);
    
    for(int i = 0; i < (int)s2.size(); ++i)
        if(s2[i] < 97) s2[i] = char(s2[i] + 32);
    
    if(s1 == s2) cout << "0" << endl;
    else if(s1 < s2) cout << "-1" << endl;
    else cout << "1" << endl;
}