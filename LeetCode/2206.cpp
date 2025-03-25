#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        const int N = nums.size();
        if (N % 2 == 1) return false;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < N - 1; i += 2) {
            if (nums[i] != nums[i+1]) return false;
        }
        return true;
    }
};