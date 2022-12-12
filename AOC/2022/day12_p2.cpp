#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int dx[4] = { 0, 0, -1, 1 };
const int dy[4] = { -1, 1, 0, 0 };

int main() {
    int N;
    cin >> N;
    vector<string> mat(N);
    for (int i = 0; i < N; i++) cin >> mat[i];
    int M = mat[0].size();
    int sx = 0, sy = 0;
    int ex = 0, ey = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (mat[i][j] == 'S') {
                sx = i; sy = j;
            } else if (mat[i][j] == 'E') {
                ex = i; ey = j;
            }
        }
    }
    auto valid = [&](int x, int y) {
        return (x >= 0 && x < N && y >= 0 && y < M);
    };
    vector<vector<int>> dist(N, vector<int>(M, INT_MAX));
    dist[ex][ey] = 0;
    queue<pair<int, int>> bfs;
    bfs.push({ ex, ey });
    mat[ex][ey] = 'z';
    mat[sx][sy] = 'a';
    while (!bfs.empty()) {
        auto top = bfs.front();
        bfs.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = top.first + dx[dir];
            int ny = top.second + dy[dir];
            if (valid(nx, ny) && 
                mat[nx][ny] >= mat[top.first][top.second] - 1
                && dist[nx][ny] > dist[top.first][top.second] + 1) {
                    dist[nx][ny] = dist[top.first][top.second] + 1;
                    bfs.push({ nx, ny });
            }
        }
    }
    int smallest = INT_MAX;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (mat[i][j] == 'a') {
                smallest = min(smallest, dist[i][j]);
            }
        }
    }
    cout << smallest << endl;
    return 0;
}