#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        const int N = nums.size();
        vector<int> frq(110);
        for (int i = N - 1; i >= 0; i--) {
            frq[nums[i]]++;
            if (frq[nums[i]] > 1) {
                return (i + 3) / 3;
            }
        }
        return 0;
    }
};