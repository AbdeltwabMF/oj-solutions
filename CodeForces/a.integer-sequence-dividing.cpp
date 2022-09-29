// https://codeforces.com/contest/1102/problem/A

#include <bits/stdc++.h>

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
    long long sum = n*(n+1) / 2;
    (sum % 2 == 0) ? cout << "0" : cout << "1";
}
