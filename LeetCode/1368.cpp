#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int N = grid.size();
        int M = grid[0].size();
        int dx[4] = { 0, 0, 1, -1 };
        int dy[4] = { 1, -1, 0, 0 };
        struct P {
            int x, y, d;
            bool operator>(const P& other) const {
                return d > other.d;
            }
        };
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({ 0, 0, 0 });
        vector<vector<int>> cost(N, vector<int>(M, 1e9));
        cost[0][0] = 0;
        while (!pq.empty()) {
            P top = pq.top();
            pq.pop();
            if (top.x == N - 1 && top.y == M - 1) return top.d;
            if (cost[top.x][top.y] < top.d) continue;
            for (int dir = 0; dir < 4; dir++) {
                int nx = top.x + dx[dir];
                int ny = top.y + dy[dir];
                if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
                    if (grid[top.x][top.y] == dir + 1) {
                        if (cost[nx][ny] > cost[top.x][top.y]) {
                            cost[nx][ny] = cost[top.x][top.y];
                            pq.push({ nx, ny, cost[nx][ny] });
                        }
                    } else {
                        if (cost[nx][ny] > cost[top.x][top.y] + 1) {
                            cost[nx][ny] = cost[top.x][top.y] + 1;
                            pq.push({ nx, ny, cost[nx][ny] });
                        }
                    }
                }
            }
        }
        return cost[N-1][M-1];
    }
};