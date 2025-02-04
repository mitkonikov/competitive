#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        const int N = nums.size();
        int ans = 1;
        vector<vector<int>> dp(2, vector<int>(N));
        dp[0][0] = dp[1][0] = 1;
        for (int i = 1; i < N; i++) {
            if (nums[i] < nums[i-1]) dp[0][i] = dp[0][i-1] + 1;
            else dp[0][i] = 1;
            if (nums[i] > nums[i-1]) dp[1][i] = dp[1][i-1] + 1;
            else dp[1][i] = 1;
            ans = max({ ans, dp[0][i], dp[1][i] });
        }
        return ans;
    }
};