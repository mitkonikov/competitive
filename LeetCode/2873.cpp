#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        const int N = nums.size();
        long long ans = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                for (int k = j + 1; k < N; k++) {
                    long long v = (long long)(nums[i] - nums[j]) * nums[k];
                    if (v < 0) v = 0;
                    ans = max(ans, v);
                }
            }
        }
        return ans;
    }
};