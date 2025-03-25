#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        const int N = nums.size();
        vector<map<int, int>> dp(N);
        dp[0][nums[0]] = 1;
        int ans = 1;
        for (int i = 1; i < N; i++) {
            dp[i][nums[i]] = 1;
            for (auto& [mask, len] : dp[i-1]) {
                if (nums[i] & mask) continue;
                const int new_mask = nums[i] | mask;
                dp[i][new_mask] = max(dp[i][new_mask], len + 1);
                ans = max(ans, dp[i][new_mask]);
            }
        }
        return ans;
    }
};