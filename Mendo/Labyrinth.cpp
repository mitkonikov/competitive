// Task: https://mendo.mk/Task.do?id=290

#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int dx[4] = { 0, 0, -1, 1 };
const int dy[4] = { -1, 1, 0, 0 };

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> mat(n);
    for (int i = 0; i < n; i++) {
        cin >> mat[i];
    }
    int sx = 0, sy = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 'P') {
                sx = i;
                sy = j;
            }
        }
    }
    auto valid = [&](int x, int y) {
        return (x >= 0 && y >= 0 && x < n && y < m);
    };
    vector<vector<vector<int>>> visited(n, vector<vector<int>>(m, vector<int>(3, INT_MAX)));
    struct bfs {
        int x, y, mod;
    };
    queue<bfs> q;
    q.push({ sx, sy, 0 }); 
    visited[sx][sy][0] = 0;
    while (!q.empty()) {
        auto top = q.front();
        q.pop();
        if (mat[top.x][top.y] == 'K') {
            cout << visited[top.x][top.y][top.mod] << endl;
            return 0;
        }

        for (int dir = 0; dir < 4; dir++) {
            int nx = top.x + (dx[dir] * (top.mod + 1));
            int ny = top.y + (dy[dir] * (top.mod + 1));
            if (!valid(nx, ny)) continue;
            
            bool ok = true;
            int nnx = top.x;
            int nny = top.y;
            for (int rep = 1; rep <= top.mod + 1; rep++) {
                nnx = top.x + (dx[dir] * rep);
                nny = top.y + (dy[dir] * rep);
                if (mat[nnx][nny] == '#') {
                    ok = false;
                    break;
                }
            }
            
            int& vis  = visited[nx][ny][(top.mod+1)%3];
            int& here = visited[top.x][top.y][top.mod];
            if (ok && mat[nx][ny] != '#' && vis > here + 1) {
                vis = here + 1;
                q.push({ nx, ny, (top.mod+1)%3 });
            }
        }
    }
    cout << -1 << endl;
    return 0;
}