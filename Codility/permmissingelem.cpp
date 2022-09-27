#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> &A) {
    long long n = A.size();
    return ((n + 2) * (n + 1) / 2) - accumulate(begin(A), end(A), 0);
}
