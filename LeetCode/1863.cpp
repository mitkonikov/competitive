#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        const int N = nums.size();
        int sum = 0;
        for (int i = 0; i < (1 << N); i++) {
            int x = 0;
            for (int j = 0; j < N; j++) {
                if (i & (1 << j)) x ^= nums[j];
            }
            sum += x;
        }
        return sum;
    }
};