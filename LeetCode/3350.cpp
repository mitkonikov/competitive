#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        const int N = nums.size();
        vector<int> dp_front(N, 1), dp_back(N, 1);
        for (int i = 1; i < N; i++) {
            if (nums[i] > nums[i-1]) dp_front[i] = dp_front[i-1] + 1;
        }
        for (int i = N - 2; i >= 0; i--) {
            if (nums[i] < nums[i+1]) dp_back[i] = dp_back[i+1] + 1;
        }
        int ans = 0;
        for (int i = 0; i < N - 1; i++) {
            ans = max(ans, min(dp_front[i], dp_back[i + 1]));
        }
        return ans;
    }
};