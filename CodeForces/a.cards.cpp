// https://codeforces.com/contest/701/problem/A

#include <bits/stdc++.h>

/** Author Abd El-Twab M. Fakhry
 *  Created at 8:30 PM -- 2019 / 04 / 5
 *  E. Cards
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
    int temp[n] = {0};

    for(int  i = 0; i < n; i++)
    {
        cin >> arr[i] ;
        temp[i] = arr[i];
    }

    sort(temp,temp+n);
    int sum = temp[0]+temp[n-1];

    for(int  i  = 0; i < n; i++)
        for(int k = i+1; k < n; k++)
            if(arr[i] + arr[k] == sum)
                cout << i+1 << " " << k+1 <<endl , arr[k] = -1 ,arr[i] = -1;
}
