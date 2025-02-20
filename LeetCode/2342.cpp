#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        const int N = nums.size();
        vector<vector<int>> sums(100);
        for (int i = 0; i < N; i++) {
            int sum = 0;
            int T = nums[i];
            while (T > 0) {
                sum += T % 10;
                T /= 10;
            }
            sums[sum].push_back(nums[i]);
        }
        int ans = -1;
        for (int i = 0; i < sums.size(); i++) {
            if (sums[i].size() < 2) continue;
            sort(sums[i].rbegin(), sums[i].rend());
            ans = max(ans, sums[i][0] + sums[i][1]);
        }
        return ans;
    }
};