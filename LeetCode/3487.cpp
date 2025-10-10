#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums.rbegin()[0] < 0) {
            return nums.rbegin()[0];
        }
        int sum = max(0, nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i-1]) sum += max(0, nums[i]);
        }
        return sum;
    }
};