#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int N = s.size();
        s = "0" + s;
        vector<int> dp(N + 1);
        dp[0] = 1;
        for (int i = 1; i <= N; i++) {
            if (s[i] != '0') {
                dp[i] = dp[i-1];
            }

            string c = s.substr(i-1, 2);
            if (c[0] != '0' && stoi(c) <= 26 && stoi(c) >= 1) {
                dp[i] += dp[i-2];
            }
        }
        return dp[N];
    }
};