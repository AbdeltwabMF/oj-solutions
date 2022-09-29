// https://codeforces.com/contest/25/problem/A

#include <bits/stdc++.h>
/**
* A. String Task
*/

using namespace std;

void fast()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
}

int main()
{
    fast();

    int n;
    cin >> n;


    int arr[n];
    int fr[2] = {0};

    for(int i = 0; i < n; i++)
        cin >> arr[i], fr[arr[i] % 2]++;
    if(fr[0] > fr[1])
    {
        for(int i = 0; i < n; i++)
            if(arr[i] % 2 == 1)
            {
                cout << i+1;
                break;
            }
    }
    else if(fr[0] < fr[1])
        for(int i = 0; i < n; i++)
            if(arr[i] % 2 == 0)
            {
                cout << i+1;
                break;
            }
}
