#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

const int dx[4] = { 0, 0, -1, 1 };
const int dy[4] = { -1, 1, 0, 0 };

void testCase() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> mat(N, vector<int>(M, 0));
    vector<vector<int>> visited(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> mat[i][j];
        }
    }
    auto valid = [&](int x, int y) {
        return (x >= 0 && y >= 0 && x < N && y < M);
    };
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (visited[i][j]) continue;
            if (mat[i][j] == 0) continue;
            queue<pair<int, int>> q;
            ll sum = 0;
            q.push({ i, j });
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                visited[x][y] = true;
                sum += mat[x][y];
                for (int dir = 0; dir < 4; dir++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if (valid(nx, ny) && mat[nx][ny] > 0) {
                        if (!visited[nx][ny]) {
                            visited[nx][ny] = true;
                            q.push({ nx, ny });
                        }
                    }
                }
            }
            ans = max(ans, sum);
        }
    }
    cout << ans << endl;
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