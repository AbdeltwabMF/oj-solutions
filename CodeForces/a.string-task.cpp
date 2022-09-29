// https://codeforces.com/contest/118/problem/A

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

    string str, temp = "";
    cin >> str;

    char vol[6] = {'a','i','u','o','e','y'};

    for(int i = 0; i < str.size(); i++)
        temp += (char)tolower(str[i]);

    for(int i = 0; i < temp.size(); i++)
        for(int j = 0; j < 6; j++)
            (temp[i] == vol[j]) ? temp[i] = '0':0;

    for(int i = 0; i < temp.size(); i++)
        if(temp[i] != '0')
            cout << "." << temp[i];
}
