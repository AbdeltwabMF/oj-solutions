class Solution {
public:
    string longestPalindrome(const string &s) {
        int n = s.size();
        int dp[1001][1001] = {};
        int mx = 0, l, r;
        for(int i = n - 1; i >= 0; --i) {
            dp[i][i] = 1;
           if(dp[i][i] >  mx) {
               mx = dp[i][i];
                l = r = i;
            }
            for(int j = i + 1; j < n; ++j) {
                if(s[i] == s[j]) {
                    int prev = dp[i + 1][j - 1];
                    dp[i][j] += prev || j - i == 1 ? prev + 2 : 0;

                    if(dp[i][j] >  mx) {
                        mx = dp[i][j];
                        l = i, r = j;
                    }
                }
            }
        }

        vector<int> v;
        int start_l = 1001;
        while(l < n && r >= 0 && dp[l][r]) {
            v.push_back(l);
            if(l != r)
                v.push_back(r);
            start_l = min({start_l, l, r});
            l++, r--;
        }

        return s.substr(start_l, v.size());
    }
};
