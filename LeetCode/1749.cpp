#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int ans = 0;
        const int N = nums.size();
        int pos = 0;
        int neg = 0;
        for (int i = 0; i < N; i++) {
            pos = max(0, pos + nums[i]);
            neg = min(0, neg + nums[i]);
            ans = max({ ans, pos, abs(neg) });
        }
        return ans;
    }
};