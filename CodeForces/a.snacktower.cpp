// https://codeforces.com/contest/767/problem/A

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
 
#define  endl                '\n'
 
void fast()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
}
 
set <int> snack;
 
int main()
{
    fast();
 
    int n;  cin >> n;
    int cnt = n;
 
    for(int i = 0; i < n; i++)
    {
        int a; cin >> a;  snack.insert(a);

        while(snack.count(cnt))
            cout << cnt << ' ', snack.erase(cnt), cnt--; cout << endl;
    }
}