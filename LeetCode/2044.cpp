#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int target = 0;
        int N = nums.size();
        for (int i = 0; i < N; i++) {
            target |= nums[i];
        }
        int ans = 0;
        for (int mask = 0; mask < (1 << N); mask++) {
            int current = 0;
            for (int i = 0; i < N; i++) {
                if (mask & (1 << i)) current |= nums[i];
            }
            if (current == target) ans++;
        }
        return ans;
    }
};