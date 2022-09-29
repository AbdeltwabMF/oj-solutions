// https://codeforces.com/contest/1143/problem/A

#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;
    int arr[n], fr[2] = {0};
    for(int  i = 0; i < n; i++)
    {
        cin >> arr[i];
        fr[arr[i]]++;
    }
    for(int  i = 0; i < n; i++)
    {
        if(arr[i] == 0)
        {
            fr[0]--;
            if(fr[0] == 0)
            {
                cout << i+1;
                break;
            }
        }
        else if(arr[i] == 1)
        {
            fr[1]--;
            if(fr[1] == 0)
            {
                cout << i+1 ;
                break;
            }
        }
    }
}
