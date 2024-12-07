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
    int H, W, D;
    cin >> H >> W >> D;
    vector<string> mat(H);
    for (int i = 0; i < H; i++) cin >> mat[i];
    struct Cell {
        int x, y, d;
        bool operator>(const Cell& other) const {
            return d > other.d;
        }
    };
    priority_queue<Cell, vector<Cell>, greater<Cell>> pq;
    vector<vector<int>> dist(H, vector<int>(W, 1e9));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (mat[i][j] == 'H') {
                pq.push({ i, j, 0 });
                dist[i][j] = 0;
            }
        }
    }
    while (!pq.empty()) {
        auto [x, y, d] = pq.top();
        pq.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (valid(nx, ny, H, W) && mat[nx][ny] == '.') {
                if (d + 1 < dist[nx][ny]) {
                    dist[nx][ny] = d + 1;
                    pq.push({ nx, ny, d + 1 });
                }
            }
        }
    }
    int count = 0; 
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (dist[i][j] <= D) count++;
        }
    }
    cout << count << endl;
    return 0;
}