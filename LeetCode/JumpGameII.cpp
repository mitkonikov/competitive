#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int N = nums.size();
        vector<int> dp(N, 1e9);
        multiset<int> current;
        vector<vector<int>> remove(N);
        dp[0] = 0;
        for (int i = 0; i < N; i++) {
            for (auto& r : remove[i]) {
                auto it = current.find(r);
                if (it != current.end()) current.erase(it);
            }

            if (!current.empty()) {
                dp[i] = *current.begin() + 1;
            }
            
            if (nums[i] > 0) {
                current.insert(dp[i]);
                if (i + nums[i] + 1 < N) {
                    remove[i + nums[i] + 1].push_back(dp[i]);
                }
            }
        }
        return dp[N-1];
    }
};