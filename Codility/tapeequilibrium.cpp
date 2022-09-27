#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> &A) {
    int n = A.size();
    int best = 0x3f3f3f3f;
    vector<int> prefixSum(n + 2, 0);
    for(int i = 0; i < n; ++i) {
        prefixSum[i + 1] = prefixSum[i] + A[i];
    }

    for(int P = 1; P < n; ++P) {
        best = min(best, abs((prefixSum[P] - prefixSum[0]) - (prefixSum[n] - prefixSum[P])));
    }
    return best;
}
