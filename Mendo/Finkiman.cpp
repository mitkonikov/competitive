// Task: https://mendo.mk/Task.do?id=140

#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int dx[4] = { 0, 0, -1, 1 };
const int dy[4] = { -1, 1, 0, 0 };

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    auto valid = [&](int x, int y) {
        return (x >= 0 && x < n && y >= 0 && y < m);
    };
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int ans = 0;
    while (true) {
        int mn = INT_MAX;
        pair<int, int> start = { -1, -1 };
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j]) {
                    if (a[i][j] < mn) {
                        mn = a[i][j];
                        start = { i, j };
                    }
                }
            }
        }
        if (mn == INT_MAX || start.first == -1) {
            break;
        }
        queue<pair<int, int>> bfs;
        bfs.push(start);
        visited[start.first][start.second] = true;
        while (!bfs.empty()) {
            auto top = bfs.front();
            bfs.pop();
            for (int dir = 0; dir < 4; dir++) {
                int nx = top.first + dx[dir];
                int ny = top.second + dy[dir];
                if (valid(nx, ny) && !visited[nx][ny] &&
                    a[nx][ny] >= a[top.first][top.second]) {
                        bfs.push({ nx, ny });
                        visited[nx][ny] = true;
                }
            }
        }
        ans++;
    }
    cout << ans << endl;
    return 0;
}