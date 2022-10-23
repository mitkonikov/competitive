#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

struct coord {
    int x, y, z;
};

int dx[6] = { -1, 1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, -1, 1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, -1, 1 };

void testCase() {
    int n, m, d;
    cin >> n >> m >> d;

    auto valid = [&](int x, int y, int z) {
        return (x >= 0 && y >= 0 && z >= 0 && x < d && y < n && z < m);
    };

    vector<vector<vector<char>>> mat(d, vector<vector<char>>(n, vector<char>(m, false)));
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                cin >> mat[i][j][k];
            }
        }
    }

    vector<vector<vector<int>>> visited(d, vector<vector<int>>(n, vector<int>(m, 0)));
    vector<int> sizes;
    bool ok = true;
    int cmp = 0;
    for (int i = 0; i < d && ok; i++) {
        for (int j = 0; j < n && ok; j++) {
            for (int k = 0; k < m && ok; k++) {
                if (visited[i][j][k]) continue;
                if (mat[i][j][k] == '#') continue;

                int count = 0;
                queue<coord> bfs;
                bfs.push({ i, j, k });
                cmp++;
                int outputs = 0;
                if (mat[i][j][k] == 'o') {
                    outputs++;
                }
                
                visited[i][j][k] = cmp;
                while (!bfs.empty()) {
                    auto top = bfs.front();
                    bfs.pop();
                    count++;

                    for (int dir = 0; dir < 6; dir++) {
                        int nx = top.x + dx[dir];
                        int ny = top.y + dy[dir];
                        int nz = top.z + dz[dir];
                        if (valid(nx, ny, nz) && visited[nx][ny][nz] == 0 && mat[nx][ny][nz] != '#') {
                            if (mat[nx][ny][nz] == 'o') {
                                outputs++;
                            }

                            visited[nx][ny][nz] = cmp;
                            bfs.push({ nx, ny, nz });
                        }
                    }
                }

                if ((count * 3 - outputs) % 2 == 0) {
                } else { ok = false; }
            }
        }
    }

    cout << (ok ? "YES" : "NO") << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    cout << flush;
    return 0;
}