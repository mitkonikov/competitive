#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int dx[8] = { 0, 0, -1, 1, 1, 1, -1, -1 };
int dy[8] = { -1, 1, 0, 0, 1, -1, 1, -1 };

bool testCase() {
    int n, m;
    cin >> n >> m;

    if (n == 0 && m == 0) {
        return false;
    }

    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    auto BFS = [&](int i, int j) {
        queue<pair<int, int>> bfs;
        bfs.push({ i, j });
        while (!bfs.empty()) {
            auto top = bfs.front();
            bfs.pop();

            if (visited[top.first][top.second]) continue;
            visited[top.first][top.second] = true;
            for (int dir = 0; dir < 8; dir++) {
                int nx = top.first + dx[dir];
                int ny = top.second + dy[dir];
                if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                    if (v[nx][ny] == v[i][j] && !visited[nx][ny]) {
                        bfs.push({ nx, ny });
                    }
                }
            }
        }
    };

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                BFS(i, j);
                count++;
            }
        }
    }

    cout << count << endl;
    return true;
}

int main() {
    while (true) {
        if (!testCase()) {
            break;
        }
    }

    cout << flush;
    return 0;
}