#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        const int N = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(N, 1), rec(N, -1);
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (nums[j] % nums[i] == 0) {
                    if (dp[i] + 1 > dp[j]) {
                        dp[j] = dp[i] + 1;
                        rec[j] = i;
                    }
                }
            }
        }
        int best = 0;
        for (int i = 0; i < N; i++) {
            if (dp[i] > dp[best]) {
                best = i;
            }
        }
        vector<int> ans;
        for (int i = best; i >= 0; i = rec[i]) {
            ans.push_back(nums[i]);
        }
        return ans;
    }
};