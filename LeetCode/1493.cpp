#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        const int N = nums.size();
        vector<int> pref(N), suff(N);
        for (int i = 0; i < N; i++) {
            if (nums[i] == 1) pref[i] = (i?pref[i-1]:0) + 1;
            else pref[i] = 0;
        }
        for (int i = N - 1; i >= 0; i--) {
            if (nums[i] == 1) suff[i] = (i<N-1?suff[i+1]:0) + 1;
            else suff[i] = 0;
        }
        int ans = 0;
        for (int i = 0; i < N; i++) {
            ans = max(ans, (i?pref[i-1]:0)+(i<N-1?suff[i+1]:0));
        }
        return ans;
    }
};