#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int ans = 0;
        int N = nums.size();
        vector<ll> pref(N), suff(N);
        for (int i = 0; i < N; i++) {
            if (i == 0) pref[i] = nums[i];
            else pref[i] = pref[i-1] + nums[i];
        }
        for (int i = N - 1; i >= 0; i--) {
            if (i == N - 1) suff[i] = nums[i];
            else suff[i] = suff[i+1] + nums[i];
        }
        for (int i = 1; i < N; i++) {
            ll L = pref[i-1];
            ll R = suff[i];
            if (L >= R) ans++;
        }
        return ans;
    }
};