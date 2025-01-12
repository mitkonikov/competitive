#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumCoins(vector<vector<int>>& coins, int k) {
        long long ans = 0;
        sort(coins.begin(), coins.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });
        int N = coins.size();
        vector<long long> pref(N);
        for (int i = 0; i < N; i++) {
            long long c = (long long)(coins[i][1] - coins[i][0] + 1) * coins[i][2];
            if (i == 0) pref[i] = c;
            else pref[i] = pref[i-1] + c;
        }
        for (int i = 0; i < N; i++) {
            int left = coins[i][0];
            int right = min(coins.back()[1], left + k - 1);
            int L = i, R = N;
            while (R - L > 1) {
                int M = (R + L) / 2;
                if (coins[M][0] <= right) {
                    L = M;
                } else {
                    R = M;
                }
            }
            int rr = L - 1;
            long long full = max(0LL, (rr >= 0 ? pref[rr] : 0) - (i > 0 ? pref[i-1] : 0));

            long long LL = coins[L][0];
            long long RR = min(right, coins[L][1]);
            long long more = (long long)(RR - LL + 1) * coins[L][2];

            ans = max(ans, full + more);
        }
        for (int i = 0; i < N; i++) {
            int right = coins[i][1];
            int left = max(coins[0][0], right - k + 1);
            int L = -1, R = i;
            while (R - L > 1) {
                int M = (R + L) / 2;
                if (coins[M][1] >= left) {
                    R = M;
                } else {
                    L = M;
                }
            }
            int rr = R + 1;
            long long full = max(0LL, pref[i] - (rr > 0 ? pref[rr-1] : 0));
            
            long long LL = max(coins[R][0], left);
            long long RR = coins[R][1];
            long long more = (long long)(RR - LL + 1) * coins[R][2];

            ans = max(ans, full + more);
        }
        return ans;
    }
};