#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int dx[4] = { 0, 0, -1, 1 };
const int dy[4] = { -1, 1, 0, 0 };
const char d[4] = { 'Z', 'V', 'S', 'J' };

int main() {
    int N, M;
    ll K;
    cin >> N >> M >> K;
    vector<vector<int>> mat(N, vector<int>(M));
    vector<vector<ll>> dp(N, vector<ll>(M));
    pair<int, int> START, END;
    int smallest = INT_MAX, biggest = INT_MIN;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> mat[i][j];
            if (mat[i][j] < smallest) {
                smallest = mat[i][j];
                START = { i, j };
            }
            if (mat[i][j] > biggest) {
                biggest = mat[i][j];
                END = { i, j };
            }
        }
    }
    auto valid = [&](int x, int y) {
        return (x >= 0 && y >= 0 && x < N && y < M);
    };
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    dp[START.first][START.second] = 1;
    visited[START.first][START.second] = true;
    auto dfs = [&](auto self, int x, int y) {
        if (visited[x][y]) return min(K, dp[x][y]);
        visited[x][y] = true;
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (valid(nx, ny) && mat[nx][ny] < mat[x][y]) {
                ll paths = self(self, nx, ny);
                dp[x][y] = min(K, dp[x][y] + paths);
            }
        }
        return min(K, dp[x][y]);
    };
    dfs(dfs, END.first, END.second);
    K = min(K, dp[END.first][END.second]);
    int cx = END.first, cy = END.second;
    string ans = "";
    vector<vector<bool>> travel(N, vector<bool>(M, 0));
    while (!(cx == START.first && cy == START.second)) {
        int last_valid_dir = -1;
        ll minus = 0;
        travel[cx][cy] = true;
        for (int dir = 3; dir >= 0; dir--) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            if (valid(nx, ny) && mat[nx][ny] < mat[cx][cy] && dp[nx][ny] > 0) {
                if (travel[nx][ny]) continue;
                if (dp[nx][ny] >= K - minus) {
                    last_valid_dir = dir;
                    break;
                }
                minus += dp[nx][ny];
            }
        }
        assert(last_valid_dir != -1);
        ans += d[last_valid_dir];
        cx += dx[last_valid_dir];
        cy += dy[last_valid_dir];
        K -= minus;
    }
    cout << ans << endl;
    return 0;
}