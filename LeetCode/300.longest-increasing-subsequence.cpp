class Solution {
public:
    int dp[2555] = {0};
    int lengthOfLIS(vector<int>& a) {
        int n = a.size();
        fill(dp, dp + n, 1);

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                if(a[i] > a[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp, dp + n);
    }
};
