#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        const int N = nums.size();
        int ans = 0;

        for (int i = 0; i < N; i++) {
            nums[i] = nums[i] % k;
        }

        vector<int> dp(k);
        for (int rem = 0; rem < k; rem++) {
            if (rem) fill(dp.begin(), dp.end(), 0);
            for (int i = 0; i < N; i++) {
                ans = max(ans, dp[nums[i]] = max(dp[nums[i]], dp[(rem - nums[i] + k) % k] + 1));
            }
        }

        return ans;
    }
};