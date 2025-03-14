#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        const int N = colors.size();
        for (int i = 0; i < N; i++) {
            colors.push_back(colors[i]);
        }
        vector<int> dp(colors.size(), 1);
        for (int i = 0; i < colors.size(); i++) {
            if (i > 0 && colors[i-1] == colors[i] ^ 1) {
                dp[i] = max(dp[i], dp[i-1] + 1);
            }
        }
        int ans = 0;
        for (int i = N; i < colors.size(); i++) {
            ans += dp[i] >= k;
        }
        return ans;
    }
};