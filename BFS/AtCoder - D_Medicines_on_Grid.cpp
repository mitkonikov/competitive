#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int H, W;
vector<vector<int>> adj;
vector<int> dfs_visited;
vector<string> A;

int mp(int x, int y) {
    return (x * W) + y;
}

const int dx[4] = { 0, 0, -1, 1 };
const int dy[4] = { -1, 1, 0, 0 };

inline bool valid(int x, int y, int w, int h) {
    return (x >= 0 && x < w && y >= 0 && y < h);
}

map<pair<int, int>, int> points;

void bfs(int x, int y, int e) {
    if (e == 0) return;
    struct BFS {
        int x, y, e;
    };
    queue<BFS> q;
    q.push({ x, y, e });
    int me = mp(x, y);
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    visited[x][y] = true;
    while (!q.empty()) {
        auto top = q.front();
        q.pop();
        for (auto dir = 0; dir < 4; dir++) {
            int nx = top.x + dx[dir];
            int ny = top.y + dy[dir];
            if (valid(nx, ny, H, W) && !visited[nx][ny] && A[nx][ny] != '#') {
                visited[nx][ny] = true;
                if (points.count({ nx, ny })) {
                    adj[me].push_back(mp(nx, ny));
                }
                if (top.e - 1 > 0) { 
                    q.push({ nx, ny, top.e - 1 });
                }
            }
        }
    }
}

void dfs(int u) {
    dfs_visited[u] = true;
    for (auto v: adj[u]) {
        if (dfs_visited[v]) continue;
        dfs(v);
    }
}

int main() {
    cin >> H >> W;
    A.resize(H);
    for (int i = 0; i < H; i++) {
        cin >> A[i];
    }
    int N;
    cin >> N;
    adj.resize(H * W + 100);
    dfs_visited.resize(H * W + 100);
    for (int i = 0; i < N; i++) {
        int X, Y, E;
        cin >> X >> Y >> E;
        X--; Y--;
        points[{ X, Y }] = E;
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (A[i][j] == 'T') {
                points[{ i, j }] = 0;
            }
        }
    }
    for (auto [p, e]: points) {
        bfs(p.first, p.second, e);
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (A[i][j] == 'S') {
                dfs(mp(i, j));
            }
        }
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (A[i][j] == 'T') {
                cout << (dfs_visited[mp(i, j)] ? "Yes" : "No") << endl;
                return 0;
            }
        }
    }
    return 0;
}