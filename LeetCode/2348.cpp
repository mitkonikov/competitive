#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        long long zeros = 0;
        nums.push_back(1);
        const int N = nums.size();
        for (int i = 0; i < N; i++) {
            if (nums[i] == 0) {
                zeros++;
            } else {
                ans += zeros * (zeros + 1) / 2;
                zeros = 0;
            }
        }
        return ans;
    }
};