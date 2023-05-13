#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<string> mat(N);
    for (int i = 0; i < N; i++) cin >> mat[i];

    const int dx[4] = { 0, 0, -1, 1 };
    const int dy[4] = { -1, 1, 0, 0 };
    auto valid = [&](int x, int y) {
        return (x >= 0 && y >= 0 && x < N && y < M);
    };

    auto bfs = [&](pair<int, int> start, pair<int, int> end) {
        queue<pair<int, int>> q;
        q.push(start);
        vector<vector<int>> visited(N, vector<int>(M, INT_MAX));
        visited[start.first][start.second] = 0;
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (valid(nx, ny) && mat[nx][ny] != '#') {
                    if (visited[nx][ny] > visited[x][y] + 1) {
                        visited[nx][ny] = visited[x][y] + 1;
                        q.push({ nx, ny });
                    }
                }
            }
        }
        return visited[end.first][end.second];
    };

    pair<int, int> START, END;
    vector<pair<int, int>> candies;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (mat[i][j] == 'S') {
                START = { i, j };
            }
            if (mat[i][j] == 'G') {
                END = { i, j };
            }
            if (mat[i][j] == 'o') {
                candies.push_back({ i, j });
            }
        }
    }

    int CC = candies.size();
    vector<vector<int>> w(CC, vector<int>(CC, INT_MAX));
    for (int i = 0; i < CC; i++) {
        for (int j = i + 1; j < CC; j++) {
            w[i][j] = w[j][i] = bfs(candies[i], candies[j]);
        }
    }

    vector<vector<int>> dp(CC, vector<int>(1 << CC, INT_MAX));
    for (int i = 0; i < CC; i++) dp[i][1 << i] = bfs(START, candies[i]);

    auto umin = [&](int& a, int b) { if (b < a) a = b; return a; };
    
    int ans = 0;
    bool ok = 0;
    for (int j = 0; j < (1 << CC); j++) { // already visited
        for (int i = 0; i < CC; i++) { // the last
            if (dp[i][j] == INT_MAX) continue;
            for (int nx = 0; nx < CC; nx++) {
                if (i == nx) continue;
                if (j & (1 << nx)) continue;
                if (w[i][nx] == INT_MAX) continue;
                umin(dp[nx][j | (1 << nx)], dp[i][j] + w[i][nx]);
            }
        }
    }

    vector<int> bfs_back(CC);
    for (int i = 0; i < CC; i++) {
        bfs_back[i] = bfs(candies[i], END);
    }

    if (bfs(START, END) <= K) ok = 1;
    for (int mask = 0; mask < (1 << CC); mask++) {
        for (int u = 0; u < CC; u++) {
            if (dp[u][mask] == INT_MAX) continue;
            if (bfs_back[u] == INT_MAX) continue;
            if (dp[u][mask] + bfs_back[u] <= K) {
                ok = 1;
                ans = max(ans, __builtin_popcount(mask));
            }
        }
    }

    cout << (ok ? ans : -1) << endl;
    return 0;
}
