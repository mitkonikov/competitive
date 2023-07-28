#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

const int dx[4] = { 0, 0, -1, 1 };
const int dy[4] = { -1, 1, 0, 0 };

vector<string> A;
vector<vector<vector<bool>>> visited;
int N, M;

inline bool valid(int x, int y, int w, int h) {
    return (x >= 0 && x < w && y >= 0 && y < h);
}

void dfs(int x, int y, int d) {
    // if there's no rock in this direction, go there
    visited[x][y][d] = true;
    int nx = x + dx[d];
    int ny = y + dy[d];
    if (valid(nx, ny, N, M) && A[nx][ny] == '.') {
        return dfs(nx, ny, d);
    }
    
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (valid(nx, ny, N, M) && !visited[nx][ny][dir] && A[nx][ny] == '.') {
            dfs(nx, ny, dir);
        }
    }
}

int main() {
    cin >> N >> M;
    A.resize(N);
    visited.resize(N, vector<vector<bool>>(M, vector<bool>(4, 0)));
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < 4; i++) dfs(1, 1, i);
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < 4; k++) {
                if (visited[i][j][k]) {
                    ans++;
                    break;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}