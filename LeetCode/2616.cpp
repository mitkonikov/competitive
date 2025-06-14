#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int N = nums.size();
        int L = -1, R = 0;
        for (int i = 0; i < N - 1; i++) {
            R = max(R, nums[i+1] - nums[i]);
        }
        while (R - L > 1) {
            int M = (R + L) / 2;
            int count = 0;
            for (int i = 0; i < N - 1; i++) {
                if (nums[i+1] - nums[i] > M) continue;
                count++;
                i++;
            }
            if (count >= p) {
                R = M;
            } else {
                L = M;
            }
        }
        return R;
    }
};