#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int S = word1.size();
        int T = word2.size();

        if (S == 0 && T == 0) return 0;
        if (S == 0) return T;
        if (T == 0) return S;

        vector<vector<int>> dp(S + 1, vector<int>(T + 1, 1e9));
        word1 = "@" + word1;
        word2 = "@" + word2;

        dp[0][0] = 0;

        for (int i = 0; i <= S; i++) {
            for (int j = 0; j <= T; j++) {
                dp[i][j] = min({
                    dp[i][j],
                    (i>0&&j>0 ? (word1[i] == word2[j] ? dp[i-1][j-1] : dp[i-1][j-1] + 1) : (int)1e9),
                    (i>0 ? dp[i-1][j] : (int)1e9) + 1,
                    (j>0 ? dp[i][j-1] : (int)1e9) + 1
                });
            }
        }

        return dp[S][T];
    }
};