class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int dp[15][10010];
        memset(dp, 0x3f3f, sizeof(dp)); // sizeof not size
        for(int i = 0; i <= n; ++i) dp[i][0] = 0;

        for(int i = 1; i <= n; ++i) { // coins
            for(int j = 0; j <= amount; ++j) { // amount
                if(j >= coins[i - 1])
                    dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i - 1]]);
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        return dp[n][amount] == 0x3f3f3f3f ? -1 : dp[n][amount];
    }
};
