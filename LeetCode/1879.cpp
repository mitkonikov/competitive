#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int N = nums1.size();
        vector<vector<int>> dp(N, vector<int>((1 << N), 1e9));
        for (int i = 0; i < N; i++) dp[i][0] = 0;
        for (int mask = 0; mask < (1 << N); mask++) {
            int bit = __builtin_popcount(mask) - 1;
            for (int i = 0; i < N; i++) {
                if (mask & (1 << i)) {
                    for (int j = 0; j < N; j++) {
                        if (bit > 0 && j == i) continue;
                        dp[i][mask] = min(dp[i][mask], dp[j][mask ^ (1 << i)] + (nums1[bit] ^ nums2[i]));
                    }
                }
            }
        }
        int target = (1 << N) - 1;
        int ans = 1e9;
        for (int k = 0; k < N; k++) {
            ans = min(ans, dp[k][target]);
        }
        return ans;
    }
};