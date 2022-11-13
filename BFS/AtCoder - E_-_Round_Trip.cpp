#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

const int dx[4] = { 0, 0, -1, 1 };
const int dy[4] = { -1, 1, 0, 0 };
int n, m;

inline bool valid(int x, int y) {
    return (x >= 0 && y >= 0 && x < n && y < m);
}

bool bfs(vector<string>& mat, int x, int y, int sx, int sy) {
    vector<vector<bool>> visited(n, vector<bool>(m, 0));
    queue<pair<int, int>> q;
    q.push({ x, y });
    visited[x][y] = true;
    while (!q.empty()) {
        auto top = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = top.first + dx[dir];
            int ny = top.second + dy[dir];
            if (valid(nx, ny) && mat[nx][ny] == '.' && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({ nx, ny });
            }
        }
    }

    for (int dir = 0; dir < 4; dir++) {
        int nx = sx + dx[dir];
        int ny = sy + dy[dir];
        auto np = make_pair(nx, ny);
        if (valid(nx, ny) && mat[nx][ny] == '.' && visited[nx][ny] && np != make_pair(x, y)) {
            return true;
        }
    }

    return false;
}

int main() {
    cin >> n >> m;
    vector<string> mat(n);
    for (int i = 0; i < n; i++) {
        cin >> mat[i];
    }

    int sx = 0, sy = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 'S') {
                sx = i;
                sy = j;
                break;
            }
        }
    }

    bool ans = 0;
    for (int dir = 0; dir < 4 && !ans; dir++) {
        int nx = sx + dx[dir];
        int ny = sy + dy[dir];
        if (valid(nx, ny) && mat[nx][ny] == '.') {
            ans |= bfs(mat, nx, ny, sx, sy);
        }
    }

    cout << (ans ? "Yes" : "No") << endl;
    cout << flush;
    return 0;
}