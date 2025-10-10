#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ptr = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == val) continue;
            nums[ptr] = nums[i];
            ptr++;
        }
        return ptr;
    }
};