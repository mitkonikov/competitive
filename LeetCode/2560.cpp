#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        const int N = nums.size();
        int L = 0, R = *max_element(nums.begin(), nums.end()) + 1;
        while (R - L > 1) {
            int M = L + (R - L) / 2;
            vector<int> dp(N + 2);
            int cur = 0;
            for (int i = 0; i < N + 2; i++) {
                if (i < N) {
                    if (nums[i] <= M) {
                        dp[i+2] = max(dp[i+2], dp[i] + 1);
                    } else {
                        dp[i+1] = max(dp[i+1], dp[i]);
                    }
                }

                cur = max(cur, dp[i]);
            }
            if (cur >= k) {
                R = M;
            } else {
                L = M;
            }
        }
        return R;
    }
};