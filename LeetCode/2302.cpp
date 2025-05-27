#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        const int N = nums.size();
        vector<ll> pref(N);
        for (int i = 0; i < N; i++) {
            pref[i] = nums[i];
            if (i) pref[i] += pref[i-1];
        }
        auto range = [&](int L, int R) {
            return pref[R] - (L ? pref[L-1] : 0);
        };
        ll ans = 0;
        for (int i = 0; i < N; i++) {
            int L = i - 1, R = N;
            while (R - L > 1) {
                int M = (R + L) / 2;
                ll sum = range(i, M);
                if (sum * (M - i + 1) < k) {
                    L = M;
                } else {
                    R = M;
                }
            }
            ans += L - i + 1;
        }
        return ans;
    }
};