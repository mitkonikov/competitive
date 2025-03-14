#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        const int N = str1.size();
        const int M = str2.size();
        vector<vector<int>> dp(N + 1, vector<int>(M + 1, 1e9));
        str1 = "@" + str1;
        str2 = "@" + str2;
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= M; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = 0;
                } else if (i == 0) {
                    dp[i][j] = j;
                } else if (j == 0) {
                    dp[i][j] = i;
                } else {
                    dp[i][j] = min({
                        dp[i][j],
                        dp[i-1][j-1] + (str1[i] == str2[j] ? 1 : 2),
                        dp[i-1][j] + 1,
                        dp[i][j-1] + 1
                    });
                }
            }
        }
        string ans = "";
        int i = N, j = M;
        while (!(i == 0 && j == 0)) {
            if (str1[i] == str2[j]) {
                ans += str1[i];
                i--; j--;
            } else {
                if (i > 0 && dp[i][j] == dp[i-1][j] + 1) {
                    ans += str1[i];
                    i--;
                } else {
                    ans += str2[j];
                    j--;
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};