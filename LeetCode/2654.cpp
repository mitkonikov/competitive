#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        const int N = nums.size();
        int g = nums[0];
        for (int i = 1; i < N; i++) {
            g = gcd(g, nums[i]);
        }
        if (g != 1) return -1;
        int c1 = 0;
        for (int i = 0; i < N; i++) {
            if (nums[i] == 1) c1++;
        }
        if (c1 > 0) return N - c1;
        int iter = 0;
        for (; nums.size() >= 2; iter++) {
            vector<int> new_nums;
            for (int j = 1; j < nums.size(); j++) {
                new_nums.push_back(gcd(nums[j], nums[j-1]));
            }
            for (int el : new_nums) {
                if (el == 1) {
                    return N + iter;
                }
            }
            nums.swap(new_nums);
        }
        return N + iter;
    }
};