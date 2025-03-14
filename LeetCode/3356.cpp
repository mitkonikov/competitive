#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        const int N = nums.size();
        const int Q = queries.size();
        auto check = [&](int M) {
            vector<long long> events(N);
            long long mx = 0;
            for (int i = 0; i < M; i++) {
                int l = queries[i][0];
                int r = queries[i][1];
                int v = queries[i][2];
                events[l] -= v;
                if (r+1<N) events[r + 1] += v;
            }
            long long pref = 0;
            for (int i = 0; i < N; i++) {
                pref += events[i];
                mx = max(mx, nums[i] + pref);
            }
            return mx;
        };
        int L = -1, R = Q;
        while (R - L > 1) {
            int M = (R + L) / 2;
            long long mx = check(M);
            if (mx <= 0) {
                R = M;
            } else {
                L = M;
            }
        }
        if (R >= 0 && R <= Q && check(R) <= 0) return R;
        return -1;
    }
};