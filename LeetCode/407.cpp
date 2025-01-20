#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        const int dx[4] = { 0, 0, 1, -1 };
        const int dy[4] = { 1, -1, 0, 0 };
        int N = heightMap.size();
        int M = heightMap[0].size();
        vector<vector<int>> dp(N, vector<int>(M, 1e9));
        struct D {
            int x, y, h;
            bool operator>(const D& other) const {
                return h > other.h;
            }
        };
        priority_queue<D, vector<D>, greater<D>> pq;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (i == 0 || j == 0 || i == N-1 || j == M-1) {
                    dp[i][j] = heightMap[i][j];
                    pq.push({ i, j, dp[i][j] });
                }
            }
        }
        while (!pq.empty()) {
            D top = pq.top();
            pq.pop();
            if (dp[top.x][top.y] < top.h) continue;
            for (int dir = 0; dir < 4; dir++) {
                int nx = top.x + dx[dir];
                int ny = top.y + dy[dir];
                if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
                    int nh = max(top.h, heightMap[nx][ny]);
                    if (dp[nx][ny] > nh) {
                        dp[nx][ny] = nh;
                        pq.push({ nx, ny, nh });
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                ans += dp[i][j] - heightMap[i][j];
            }
        }
        return ans;
    }
};