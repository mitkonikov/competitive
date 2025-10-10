#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        const int N = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        int len = 0;
        int ans = 1;
        for (int i = 0; i < N; i++) {
            if (nums[i] == mx) {
                len++;
                ans = max(ans, len);
            } else {
                len = 0;
            }
        }
        return ans;
    }
};