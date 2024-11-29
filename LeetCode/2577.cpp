#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        const int N = grid.size();
        const int M = grid[0].size();
        const int dx[4] = { 0, 0, -1, 1 };
        const int dy[4] = { 1, -1, 0, 0 };
        struct D {
            int time, x, y;
            bool operator>(const D& other) const {
                return time > other.time;
            }
        };
        priority_queue<D, vector<D>, greater<D>> q;
        vector<vector<int>> least_time(N, vector<int>(M, 1e9));
        q.push({ 0, 0, 0 });
        least_time[0][0] = 0;
        bool nnn = false;
        nnn |= (N > 1 && grid[1][0] <= 1);
        nnn |= (M > 1 && grid[0][1] <= 1);
        while (!q.empty()) {
            auto t = q.top();
            q.pop();
            if (least_time[t.x][t.y] < t.time) continue;
            for (int dir = 0; dir < 4; dir++) {
                int nx = t.x + dx[dir];
                int ny = t.y + dy[dir];
                if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
                    if (grid[nx][ny] <= t.time + 1 && least_time[nx][ny] == 1e9) {
                        least_time[nx][ny] = t.time + 1;
                        q.push({ t.time + 1, nx, ny });
                    } else if (!(t.x == 0 && t.y == 0 && !nnn) && grid[nx][ny] >= t.time + 1) {
                        int waste = 0;
                        int diff = grid[nx][ny] - least_time[t.x][t.y];
                        if (diff % 2 == 0) waste += 1;
                        // 4 6 -> 6 6 -> waste
                        if (least_time[nx][ny] > grid[nx][ny] + waste) {
                            least_time[nx][ny] = grid[nx][ny] + waste;
                            q.push({ grid[nx][ny] + waste, nx, ny });
                        }
                    }
                }
            }
        }
        if (least_time[N-1][M-1] == 1e9) return -1;
        return least_time[N-1][M-1];
    }
};