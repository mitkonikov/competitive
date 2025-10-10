#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        cin.tie(0)->sync_with_stdio(false);
        const int N = grid.size();
        const int M = grid[0].size();
        int ans = 0;
        vector<vector<vector<int>>> dp(4, vector<vector<int>>(N, vector<int>(M, 0)));
        const int dx[4] = { -1, -1, 1, 1 };
        const int dy[4] = { -1, 1, 1, -1 };

        // Precompute DP
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (grid[i][j] == 1) continue;
                for (auto dir : { 0, 1 }) {
                    dp[dir][i][j] = 1;
                    int x = i + dx[dir];
                    int y = j + dy[dir];
                    if (x >= 0 && y >= 0 && x < N && y < M) {
                        if (grid[x][y] != grid[i][j]) {
                            dp[dir][i][j] = max(dp[dir][i][j], dp[dir][x][y] + 1);
                        }
                    }
                }
            }
        }

        for (int i = N - 1; i >= 0; i--) {
            for (int j = 0; j < M; j++) {
                if (grid[i][j] == 1) continue;
                for (auto dir : { 2, 3 }) {
                    dp[dir][i][j] = 1;
                    int x = i + dx[dir];
                    int y = j + dy[dir];
                    if (x >= 0 && y >= 0 && x < N && y < M) {
                        if (grid[x][y] != grid[i][j]) {
                            dp[dir][i][j] = max(dp[dir][i][j], dp[dir][x][y] + 1);
                        }
                    }
                }
            }
        }

        for (int dir = 0; dir < 4; dir++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    if (grid[i][j] != 1) continue;
                    ans = max(ans, 1);
                    int len = 1;
                    int x = i;
                    int y = j;
                    x += dx[dir];
                    y += dy[dir];
                    while (x >= 0 && y >= 0 && x < N && y < M) {
                        if ((len % 2 == 1 && grid[x][y] == 2) || 
                            (len % 2 == 0 && grid[x][y] == 0)) {
                                len++;
                                ans = max(ans, len);
                                {
                                    int x2 = x + dx[(dir+1)%4];
                                    int y2 = y + dy[(dir+1)%4];
                                    if (x2 >= 0 && y2 >= 0 && x2 < N && y2 < M && grid[x2][y2] != grid[x][y]) {
                                        ans = max(ans, len + dp[(dir+1)%4][x2][y2]);
                                    }
                                }
                                x += dx[dir];
                                y += dy[dir];
                            } else {
                                break;
                            }
                    }
                }
            }
        }
        return ans;
    }
};