#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int MX = 370;
        vector<int> pref(MX);
        for (int i = 0; i < days.size(); i++) {
            pref[days[i]]++;
        }
        for (int i = 1; i < MX; i++) {
            pref[i] += pref[i-1];
        }
        vector<int> dp(MX, 1e9);
        dp[0] = 0;
        vector<int> d = { 1, 7, 30 };
        for (int i = 1; i <= 365; i++) {
            for (auto rep = 0; rep < 3; rep++) {
                int sum = pref[i] - (i - d[rep] >= 0 ? pref[i-d[rep]] : 0);
                if (sum == 0) dp[i] = min(dp[i], dp[i-1]);
                else dp[i] = min(dp[i], dp[max(0, i-d[rep])] + costs[rep]);
            }
        }
        return dp[365];
    }
};