#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        const int N = grid.size();
        int mx = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                mx = max(mx, grid[i][j]);
            }
        }
        int dx[4] = { 1, -1, 0, 0 };
        int dy[4] = { 0, 0, 1, -1 };
        int L = -1, R = mx;
        while (R - L > 1) {
            int M = (R + L) / 2;
            vector<vector<bool>> visited(N, vector<bool>(N, false));
            queue<pair<int, int>> q;
            if (grid[0][0] <= M) {
                q.push({ 0, 0 });
                visited[0][0] = true;
            }
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
                        if (!visited[nx][ny] && grid[nx][ny] <= M) {
                            visited[nx][ny] = true;
                            q.push({ nx, ny });
                        }
                    }
                }
            }
            if (visited[N-1][N-1]) {
                R = M;
            } else {
                L = M;
            }
        }
        return R;
    }
};