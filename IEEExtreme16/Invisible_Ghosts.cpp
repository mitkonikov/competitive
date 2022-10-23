#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

const int dx[4] = { 1, 0, 0, -1 };
const int dy[4] = { 0, -1, 1, 0 };

struct where {
    int x, y;
    char dir;
};

char dd[4] = { 'D', 'L', 'R', 'U', };

void testCase() {
    int n, m;
    cin >> n >> m;

    vector<string> mat(n);
    for (int i = 0; i < n; i++) {
        cin >> mat[i];
    }

    vector<vector<int>> ghosts(n, vector<int>(m, INT_MAX));
    vector<vector<int>> packman(n, vector<int>(m, INT_MAX));
    vector<vector<where>> from_where(n, vector<where>(m, {-1, -1}));

    auto valid = [&](int i, int j) {
        return (i >= 0 && j >= 0 && i < n && j < m);
    };

    auto bfs = [&](int i, int j, vector<vector<int>>& dist, bool mem) {
        queue<pair<int, int>> q;
        q.push({ i, j });
        dist[i][j] = 0;
        while (!q.empty()) {
            auto top = q.front();
            q.pop();

            for (int dir = 0; dir < 4; dir++) {
                int nx = top.first + dx[dir];
                int ny = top.second + dy[dir];
                if (valid(nx, ny) && mat[nx][ny] != 'X') {
                    if (dist[top.first][top.second] + 1 < dist[nx][ny]) {
                        dist[nx][ny] = dist[top.first][top.second] + 1;
                        q.push({ nx, ny });

                        if (mem) {
                            from_where[nx][ny] = {
                                top.first,
                                top.second,
                                dd[dir]
                            };
                        }
                    }
                }
            }
        }
    };

    int px = -1, py = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 'P') {
                px = i;
                py = j;
                bfs(i, j, packman, true);
            } else if (mat[i][j] == 'G') {
                bfs(i, j, ghosts, false);
            }
        }
    }

    int bx = 10000, by = 10000;
    int bt = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (packman[i][j] == INT_MAX) continue;
            if (packman[i][j] < ghosts[i][j]) {
                if (ghosts[i][j] > bt) {
                    bx = i;
                    by = j;
                    bt = ghosts[i][j];
                } else if (ghosts[i][j] == bt) {
                    if (make_pair(i, j) < make_pair(bx, by)) {
                        bx = i;
                        by = j;
                        bt = ghosts[i][j];
                    }
                }
            }
        }
    }

    auto go = [&](int i, int j, bool stay) {
        string res = "";
        auto here = from_where[i][j];
        while (here.x != -1) {
            res += here.dir;
            here = from_where[here.x][here.y];
        }
        reverse(res.begin(), res.end());
        if (res.empty()) {
            if (stay) cout << "STAY" << endl;
            return;
        }
        cout << res << endl;
    };

    if (bt == INT_MAX) {
        cout << "INFINITE ";
        go(bx, by, true);
        return;
    }

    cout << bt - 1 << " ";
    go(bx, by, true);
}

int main() {
    int t;
    cin >> t;

    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        testCase();
    }

    cout << flush;
    return 0;
}