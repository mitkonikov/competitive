#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

const int dx[4] = { 0, 1, 0, -1 };
const int dy[4] = { 1, 0, -1, 0 };

inline bool valid(int x, int y, int w, int h) {
    return (x >= 0 && x < w && y >= 0 && y < h);
}

int main() {
    int N;
    cin >> N;
    vector<vector<int>> mat(N, vector<int>(N, 0));
    int dir = 0;
    int x = 0, y = 0;
    int counter = 1;
    for (int i = 1; i <= N * N - 1; i++) {
        mat[x][y] = counter++;
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (!valid(nx, ny, N, N) || mat[nx][ny] != 0) {
            dir = (dir + 1) % 4;
        }
        nx = x + dx[dir];
        ny = y + dy[dir];
        x = nx;
        y = ny;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (mat[i][j] == 0) {
                cout << "T" << " ";
            } else {
                cout << mat[i][j] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}