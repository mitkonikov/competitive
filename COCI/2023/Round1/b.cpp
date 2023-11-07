#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

const int dx[4] = { 0, 0, -1, 1 };
const int dy[4] = { -1, 1, 0, 0 };

inline bool valid(int x, int y, int w, int h) {
    return (x >= 0 && x < w && y >= 0 && y < h);
}

inline int color(char c) {
    if (c == 'P') return 1;
    if (c == 'C') return 2;
    if (c == 'Z') return 4;
    return 8;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, M;
    cin >> N >> M;
    vector<string> DY(N);
    for (int i = 0; i < N; i++) cin >> DY[i];
    vector<string> DX(N - 1);
    for (int i = 0; i < N - 1; i++) cin >> DX[i];
    int Q;
    cin >> Q;
    struct D {
        int x, y, c;
        bool operator>(const D& other) const {
            return __builtin_popcount(c) > __builtin_popcount(other.c);
        }
    };
    for (int i = 0; i < Q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--; b--; c--; d--;
        vector<vector<vector<int>>> dist(N, vector<vector<int>>(M, vector<int>(16, 1e9)));
        dist[a][b][0] = 0;
        queue<D> pq;
        pq.push({ a, b, 0 });
        while (!pq.empty()) {
            auto t = pq.front();
            pq.pop();
            for (int dir = 0; dir < 4; dir++) {
                int nx = t.x + dx[dir];
                int ny = t.y + dy[dir];
                if (valid(nx, ny, N, M)) {
                    char next_color = 0;
                    if (ny > t.y) next_color = DY[t.x][t.y];
                    if (ny < t.y) next_color = DY[t.x][t.y-1];
                    if (nx > t.x) next_color = DX[t.x][t.y];
                    if (nx < t.x) next_color = DX[t.x-1][t.y];
                    int nxc = color(next_color);
                    D new_state = { nx, ny, t.c | nxc };
                    if (dist[nx][ny][t.c | nxc] > dist[t.x][t.y][t.c] + 1) {
                        dist[nx][ny][t.c | nxc] = dist[t.x][t.y][t.c] + 1;
                        pq.push(new_state);
                    }
                }
            }
        }
        int ans = 1e9;
        for (int i = 0; i < 16; i++) {
            if (dist[c][d][i] != 1e9) {
                ans = min(ans, __builtin_popcount(i));
            }
        }
        cout << ans << endl;
    }
    return 0;
}