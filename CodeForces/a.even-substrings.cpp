// https://codeforces.com/contest/1139/problem/A

#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, cnt =0;
    string s;
    cin >> n;
    cin >> s;

    for(int i = 0; i < n; i++)
    {
        int c = (int)s[i];
        if(c % 2 == 0)
        {
            for(int j = i; j >= 0; j--)
            {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}
