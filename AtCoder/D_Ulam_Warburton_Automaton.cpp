#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<pair<int, int>> q;
    vector<vector<int>> mark(N, vector<int>(M, 0));
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (A[i][j] == '#') {
                q.push_back({ i, j });
                mark[i][j] = 1;
                ans++;
            }
        }
    }
    const int dx[4] = { 0, 0, -1, 1 };
    const int dy[4] = { -1, 1, 0, 0 };
    while (!q.empty()) {
        vector<pair<int, int>> possible;
        for (auto& [x, y] : q) {
            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
                    mark[nx][ny]++;
                    possible.push_back({ nx, ny });
                }
            }
        }
        vector<pair<int, int>> new_black;
        for (auto& [x, y] : possible) {
            if (mark[x][y] == 1) {
                new_black.push_back({ x, y });
                ans++;
            }
        }
        q.swap(new_black);
    }
    cout << ans << endl;
    return 0;
}