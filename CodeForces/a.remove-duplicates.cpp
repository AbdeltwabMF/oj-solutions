// https://codeforces.com/contest/978/problem/A

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

/** Author  : Abd El-Twab M. Fakhry
*   Created : 8:00 PM :: 26/04/2019
*/

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

#define  endl                '\n'
#define  loop0(i , n)        for(int i = 0; i < (n); i++)
#define  loop1(i , n)        for(int i = 1; i <= (n); i++)
#define  loopEn(i , x , n)   for(int i = (x); i <= (n); i++)

void fast()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
}

set <int> dad;
deque <int> dedy;

int main()
{
    fast();

    int n;
    cin >> n;
    int arr[n];

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }


    for(int i = n-1; i >= 0; i--)
    {
        if(dad.find(arr[i]) == dad.end())
        {
            dedy.push_front(arr[i]);
            dad.insert(arr[i]);
        }
    }
    cout << dad.size() << endl;
    for(int i = 0; i < dedy.size(); i++)
        cout << dedy[i] << " ";
}
