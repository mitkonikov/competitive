#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        // even even even even
        // odd odd odd odd
        // odd even odd even
        // even odd even odd
        const int N = nums.size();
        vector<vector<int>> dp(N, vector<int>(4, 0));
        int ans = 0;
        for (int i = 0; i < N; i++) {
            if (i) for (int r = 0; r < 4; r++) dp[i][r] = dp[i-1][r];

            dp[i][nums[i] & 1]++;
            if (nums[i] & 1) dp[i][2] = max(dp[i][2], (i?dp[i-1][3]:0) + 1);
            else dp[i][3] = max(dp[i][3], (i?dp[i-1][2]:0) + 1);

            for (int r = 0; r < 4; r++) ans = max(ans, dp[i][r]);
        }
        return ans;
    }
};