#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        const int N = isWater.size();
        const int M = isWater[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> ans(N, vector<int>(M, 1e9));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (isWater[i][j] == 1) {
                    q.push({ i, j });
                    ans[i][j] = 0;
                }
            }
        }
        const int dx[4] = { 0, 0, 1, -1 };
        const int dy[4] = { -1, 1, 0, 0 };
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
                    if (ans[nx][ny] == 1e9) {
                        ans[nx][ny] = ans[x][y] + 1;
                        q.push({ nx, ny });
                    }
                }
            }
        }
        return ans;
    }
};