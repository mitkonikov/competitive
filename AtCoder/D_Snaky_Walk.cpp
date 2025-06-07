#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

const int dx[4] = { 0, 0, -1, 1 };
const int dy[4] = { -1, 1, 0, 0 };

inline bool valid(int x, int y, int w, int h) {
    return (x >= 0 && x < w && y >= 0 && y < h);
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<vector<vector<int>>> dist(N, vector<vector<int>>(M, vector<int>(2, 1e9)));
    pair<int, int> start, goal;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (A[i][j] == 'S') start = { i, j };
            else if (A[i][j] == 'G') goal = { i, j };
        }
    }
    dist[start.first][start.second][0] = 0;
    dist[start.first][start.second][1] = 0;
    struct D {
        int x, y, d, c;
        bool operator>(const D& other) const {
            return c > other.c;
        }
    };
    priority_queue<D, vector<D>, greater<D>> pq;
    pq.push({ start.first, start.second, 0, 0 });
    pq.push({ start.first, start.second, 1, 0 });
    while (!pq.empty()) {
        auto [x, y, d, c] = pq.top();
        pq.pop();
        for (int dir = 0; dir < 4; dir++) {
            if (d == 0 && dir < 2) continue;
            if (d == 1 && dir >= 2) continue;
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (valid(nx, ny, N, M) && A[nx][ny] != '#') {
                if (dist[nx][ny][d^1] > c + 1) {
                    dist[nx][ny][d^1] = c + 1;
                    pq.push({ nx, ny, d^1, c + 1 });
                }
            }
        }
    }
    int ans = min(dist[goal.first][goal.second][0], dist[goal.first][goal.second][1]);
    if (ans == 1e9) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}