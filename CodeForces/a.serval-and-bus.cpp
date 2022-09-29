// https://codeforces.com/contest/1153/problem/A

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

pair <int, int> p;

int main()
{
    fast();

    int n, t, s, d, mn = INT_MAX;
    cin >> n >> t;

    for(int i = 1; i <= n; i++)
    {
        cin >> s >> d;

        while(s < t)
            s+=d;

        if(s < mn)
        {
            mn = min(mn, s);
            p = {mn , i};
        }
    }
    cout << p.second << '\n';
}
