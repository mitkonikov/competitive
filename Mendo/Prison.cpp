// Task: https://mendo.mk/Task.do?id=117

#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int dx[4] = { 0, 0, -1, 1 };
const int dy[4] = { -1, 1, 0, 0 };

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> mat(n);
    vector<pair<int, int>> guards;
    pair<int, int> start, end;
    for (int i = 0; i < n; i++) {
        cin >> mat[i];
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 'G') {
                guards.push_back({ i, j });
            } else if (mat[i][j] == 'R') {
                start = { i, j };
            } else if (mat[i][j] == 'Z') {
                end = { i, j };
            }
        }
    }
    auto valid = [&](int x, int y) {
        return (x >= 0 && x < n && y >= 0 && y < m);
    };
    vector<vector<int>> mn(n, vector<int>(m, INT_MAX));
    for (auto guard: guards) {
        queue<pair<int, int>> bfs;
        bfs.push(guard);
        mn[guard.first][guard.second] = 0;
        while (!bfs.empty()) {
            auto top = bfs.front();
            bfs.pop();

            for (int dir = 0; dir < 4; dir++) {
                int nx = top.first + dx[dir];
                int ny = top.second + dy[dir];
                if (valid(nx, ny) && (mat[nx][ny] == '.' || mat[nx][ny] == 'R' || mat[nx][ny] == 'Z') && mn[nx][ny] > mn[top.first][top.second] + 1) {
                    mn[nx][ny] = mn[top.first][top.second] + 1;
                    bfs.push({ nx, ny });
                }
            }
        }
    }
    struct go {
        int x, y, cost;
        bool operator<(const go& other) const {
            return (cost < other.cost);
        }
    };
    priority_queue<go, vector<go>, less<go>> pq;
    pq.push({ start.first, start.second, mn[start.first][start.second] });
    vector<vector<int>> ans(n, vector<int>(m, INT_MIN));
    ans[start.first][start.second] = mn[start.first][start.second];
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        
        for (int dir = 0; dir < 4; dir++) {
            int nx = top.x + dx[dir];
            int ny = top.y + dy[dir];
            if (valid(nx, ny) && (mat[nx][ny] == '.' || make_pair(nx, ny) == end)) {
                int new_cost = min(top.cost, mn[nx][ny]);
                if (new_cost > ans[nx][ny]) {
                    ans[nx][ny] = new_cost;
                    pq.push({ nx, ny, new_cost });
                }
            }
        }
    }
    cout << ans[end.first][end.second] << endl;
    return 0;
}