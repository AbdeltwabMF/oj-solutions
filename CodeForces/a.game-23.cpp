// https://codeforces.com/contest/1141/problem/A

#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    long long n, m, cnt = 0;
    cin >> n >> m;

    if(n == m)
    {
        cout << "0" <<endl;
    }
    else if(n > m)
    {
        cout << "-1" <<endl;
    }
    else
    {
        while(m > n)
        {
            if(m % (n*2) == 0)
            {
                n = n * 2;
                cnt++;
            }
            else if(m % (n*3) == 0)
            {
                n = n * 3;
                cnt++;
            }
            else
            {
                cnt = -1;
                break;
            }
        }
            cout << cnt<<endl;
    }
}

