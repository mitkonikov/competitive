#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        const int N = nums.size();
        vector<long long> pref_max(N), suff_max(N);
        for (int i = 0; i < N; i++) {
            if (i == 0) pref_max[i] = nums[i];
            else pref_max[i] = max(pref_max[i-1], (long long)nums[i]);
        }
        for (int i = N - 1; i >= 0; i--) {
            if (i == N - 1) suff_max[i] = nums[i];
            else suff_max[i] = max(suff_max[i+1], (long long)nums[i]);
        }
        long long ans = 0;
        for (int i = 1; i < N - 1; i++) {
            ans = max(ans, (long long)(pref_max[i-1] - nums[i]) * suff_max[i+1]);
        }
        return ans;
    }
};