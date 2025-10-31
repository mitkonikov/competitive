#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        set<int> s;
        const int N = nums.size();
        vector<int> ans;
        for (int i = 0; i < N; i++) {
            if (s.count(nums[i])) ans.push_back(nums[i]);
            else s.insert(nums[i]);
        }
        return ans;
    }
};