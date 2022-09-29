// https://codeforces.com/contest/339/problem/A

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

    string str, nums = "", sign = "";
    cin >> str;


    for(int i = 0; i < str.size(); i++)
        (str[i] != '+') ? nums += str[i] : sign += str[i];
    sort(nums.begin(), nums.end());

    int sz = sign.size();

    for(int i = 0; i < nums.size(); i++)
        (sz-- > 0) ?  cout << nums[i] << "+" : cout << nums[i];
}
