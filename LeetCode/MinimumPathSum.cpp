#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int N = grid.size();
        int M = grid[0].size();
        vector<vector<int>> dp(N, vector<int>(M, 1e9));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (i == 0 && j == 0) dp[i][j] = grid[i][j];
                else if (i == 0) dp[i][j] = min(dp[i][j], dp[i][j-1] + grid[i][j]);
                else if (j == 0) dp[i][j] = min(dp[i][j], dp[i-1][j] + grid[i][j]);
                else dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + grid[i][j];
            }
        }
        return dp[N-1][M-1];
    }
};