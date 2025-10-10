#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        const int N = nums.size();
        vector<int> vec{ nums[0] };
        for (int i = 1; i < N - 1; i++) {
            if (nums[i] != nums[i-1]) {
                vec.push_back(nums[i]);
            }
        }
        vec.push_back(nums.back());
        int ans = 0;
        for (int i = 1; i < vec.size() - 1; i++) {
            if (vec[i] > vec[i-1] && vec[i] > vec[i+1]) ans++;
            if (vec[i] < vec[i-1] && vec[i] < vec[i+1]) ans++;
        }
        return ans;
    }
};