#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        const int N = nums.size();
        int ans = 0;
        for (int i = 0; i + 2 < N; i++) {
            if (nums[i] == 0) {
                ans++;
                for (int j = 0; j < 3; j++) {
                    nums[i+j] ^= 1;
                }
            }
        }
        for (int i = 0; i < N; i++) {
            if (nums[i] == 0) return -1;
        }
        return ans;
    }
};