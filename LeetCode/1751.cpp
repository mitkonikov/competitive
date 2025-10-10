#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int maxValue(vector<vector<int>>& events, int K) {
        sort(events.begin(), events.end(), [](vector<int>& a, vector<int>& b) {
            if (a[1] == b[1]) return a[0] < b[0];
            return a[1] < b[1];
        });
        const int N = events.size();
        vector<map<int, ll>> dp(K + 1);
        dp[0][0] = 0;
        ll ans = 0;
        for (int i = 0; i < N; i++) {
            for (int k = 1; k <= K; k++) {
                // dp[k][end_day] = dp[k-1][start_day-1] + value[i]
                // dp[k][end_day] = dp[k][end_day-1]
                const auto start_day = events[i][0];
                const auto end_day = events[i][1];
                const auto value = events[i][2];
                
                auto it = dp[k-1].lower_bound(start_day);
                if (it != dp[k-1].begin()) {
                    it = prev(it);
                    dp[k][end_day] = max(dp[k][end_day], it->second + value);
                    ans = max(ans, it->second + value);
                }

                auto it_1 = dp[k].lower_bound(end_day);
                if (it_1 != dp[k].begin()) {
                    it_1 = prev(it_1);
                    dp[k][end_day] = max(dp[k][end_day], it_1->second);
                    ans = max(ans, dp[k][end_day]);
                }
            }
        }
        return ans;
    }
};