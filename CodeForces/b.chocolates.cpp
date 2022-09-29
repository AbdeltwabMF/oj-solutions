// https://codeforces.com/contest/1139/problem/B

#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    long long cnt = 0, mn = 0;
    cin >> n;

    int arr [n];
    for(int  i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    mn  = arr[n-1];
        for(int  j = n-2; j >= 0; j--)
        {
            if(arr[j] < mn)
            {
                cnt += arr[j];
                mn = arr[j];
            }
            else
            {
                cnt += (mn - 1);
                mn = mn - 1;
                if(mn <= 0)
                  break;
            }
        }
    cout << (cnt+arr[n-1]) <<endl;
}
