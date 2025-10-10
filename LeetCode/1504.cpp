#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        const int N = mat.size();
        const int M = mat[0].size();
        vector<vector<int>> dp(N, vector<int>(M, 0));
        for (int i = 0; i < N; i++) {
            int cur = 0;
            for (int j = 0; j < M; j++) {
                if (mat[i][j] == 1) {
                    cur++;
                } else {
                    cur = 0;
                }
                dp[i][j] = cur;
            }
        }
        int ans = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int cur = dp[i][j];
                for (int k = i; k >= 0; k--) {
                    cur = min(cur, dp[k][j]);
                    ans += cur;
                }
            }
        }
        return ans;
    }
};