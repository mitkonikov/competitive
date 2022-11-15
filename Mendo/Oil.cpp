// Task: https://mendo.mk/Task.do?id=277

#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int dx[8] = { 0, 0, -1, 1, 1, -1, 1, -1 };
const int dy[8] = { -1, 1, 0, 0, 1, -1, -1, 1 };

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> mat(n);
    for (int i = 0; i < n; i++) cin >> mat[i];
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int comps = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == '*') continue;
            if (visited[i][j]) continue;
            comps++;
            queue<pair<int, int>> bfs;
            bfs.push({ i, j });
            while (!bfs.empty()) {
                auto top = bfs.front();
                bfs.pop();
                for (int dir = 0; dir < 8; dir++) {
                    int nx = top.first + dx[dir];
                    int ny = top.second + dy[dir];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && mat[nx][ny] == '@') {
                        visited[nx][ny] = true;
                        bfs.push({ nx, ny });
                    }
                }
            }
        }
    }
    cout << comps << endl;
    return 0;
}