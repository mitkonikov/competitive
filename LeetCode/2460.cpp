#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        const int N = nums.size();
        for (int i = 0; i < N - 1; i++) {
            if (nums[i] == nums[i+1]) {
                nums[i] *= 2;
                nums[i+1] = 0;
            }
        }
        vector<int> ans;
        ans.reserve(N);
        for (int i = 0; i < N; i++) {
            if (nums[i] != 0) {
                ans.push_back(nums[i]);
            }
        }
        while (ans.size() < N) ans.push_back(0);
        return ans;
    }
};