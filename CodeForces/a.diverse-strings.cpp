// https://codeforces.com/contest/1144/problem/A

#include <bits/stdc++.h>

/** Author  : Abd El-Twab M. Fakhry
 *  Created : 00:00 M   -|-   - 04 - 2019
 */

using namespace std;

#define  endl           '\n'
#define  loop(n)        for(int i = 0; i < (n); i++)

void fast()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
}

int fr[1];

int main()
{
    fast();

    int n;
    cin >> n;

    while(n--)
    {
        int cnt = 0;
        string s;
        cin >> s;

        sort(s.begin(), s.end());

        for(int i = s.size()-1; i > 0; i--)
            if(s[i] - s[i-1] == 1)
                cnt++;

        if(cnt == s.size()-1)
            cout <<  "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
}
