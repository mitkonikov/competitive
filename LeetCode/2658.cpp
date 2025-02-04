#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        const int dx[4] = { 0, 0, -1, 1 };
        const int dy[4] = { 1, -1, 0, 0 };
        const int N = grid.size();
        const int M = grid[0].size();
        int ans = 0;
        vector<vector<bool>> visited(N, vector<bool>(M, false));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (visited[i][j]) continue;
                if (grid[i][j] == 0) continue;
                int count = 0;
                queue<pair<int, int>> q;
                q.push({ i, j });
                visited[i][j] = true;
                while (!q.empty()) {
                    auto t = q.front();
                    q.pop();
                    const int x = t.first;
                    const int y = t.second;
                    count += grid[x][y];
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = x + dx[dir];
                        int ny = y + dy[dir];
                        if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
                            if (!visited[nx][ny] && grid[nx][ny] > 0) {
                                visited[nx][ny] = true;
                                q.push({ nx, ny });
                            }
                        }
                    }
                }
                ans = max(ans, count);
            }
        }
        return ans;
    }
};