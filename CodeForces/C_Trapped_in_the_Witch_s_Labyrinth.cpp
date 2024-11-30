#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

const int dx[4] = { 0, 0, -1, 1 };
const int dy[4] = { -1, 1, 0, 0 };
const char c[4] = { 'L', 'R', 'U', 'D' };
const int op[4] = { 1, 0, 3, 2 };

inline bool valid(int x, int y, int w, int h) {
    return (x >= 0 && x < w && y >= 0 && y < h);
}

void testCase() {
    int N, M;
    cin >> N >> M;
    vector<string> maze(N);
    for (int i = 0; i < N; i++) {
        cin >> maze[i];
    }
    vector<vector<bool>> getout(N, vector<bool>(M, false));
    queue<pair<int, int>> bfs;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (maze[i][j] == '?') continue;
            for (int dir = 0; dir < 4; dir++) {
                if (maze[i][j] == c[dir]) {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if (!valid(nx, ny, N, M)) {
                        getout[i][j] = true;
                        bfs.push({ i, j });
                    }
                }
            }
        }
    }
    auto points = [&](char ch) {
        for (int dir = 0; dir < 4; dir++) {
            if (c[dir] == ch) {
                return dir;
            }
        }
        return 0;
    };
    while (!bfs.empty()) {
        auto [x, y] = bfs.front();
        bfs.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (valid(nx, ny, N, M) && maze[nx][ny] != '?') {
                char him = maze[nx][ny];
                int him_dir = points(him);
                if (him_dir == op[dir]) {
                    if (!getout[nx][ny]) {
                        getout[nx][ny] = true;
                        bfs.push({ nx, ny });
                    }
                }
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (maze[i][j] != '?') continue;
            int cnt = 0;
            for (int dir = 0; dir < 4; dir++) {
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                if (!valid(nx, ny, N, M)) {
                    cnt++;
                }
                if (valid(nx, ny, N, M) && getout[nx][ny]) {
                    cnt++;
                }
            }
            if (cnt == 4) {
                getout[i][j] = true;
            }
        }
    }
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            count += !getout[i][j];
        }
    }
    cout << count << endl;
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