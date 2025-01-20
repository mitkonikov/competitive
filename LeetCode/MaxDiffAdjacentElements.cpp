#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int mx = 0;
        for (int i = 0; i < nums.size(); i++) {
            mx = max(mx, abs(nums[i] - nums[(i+1)%nums.size()]));
        }
        return mx;
    }
};