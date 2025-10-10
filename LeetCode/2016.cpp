#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int mx = -1;
        const int N = nums.size();
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (nums[j] > nums[i]) {
                    mx = max(mx, nums[j] - nums[i]);
                }
            }
        }
        return mx;
    }
};