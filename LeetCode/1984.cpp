#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if (k == 1) return 0;
        int ans = INT_MAX;
        const int N = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < N - k + 1; i++) {
            ans = min(ans, nums[i + k - 1] - nums[i]);
        }
        return ans;
    }
};