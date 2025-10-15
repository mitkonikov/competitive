#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        const int N = nums.size();
        for (int i = k; i < N; i++) {
            if (i + k > N) continue;
            bool okA = true;
            bool okB = true;
            for (int j = i - k; j < i - 1; j++) {
                okA &= (nums[j] < nums[j+1]);
            }
            for (int j = i; j < i + k - 1; j++) {
                okB &= (nums[j] < nums[j+1]);
            }
            if (okA && okB) return true;
        }
        return false;
    }
};