#include <bits/stdc++.h>
#define ll long long

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
    vector<vector<vector<bool>>> dp(N, vector<vector<bool>>(M, vector<bool>(5, 0)));
    struct BFS {
        int x, y, l;
    };
    queue<BFS> bfs;
    if (A[0][0] == 's') {
        dp[0][0][0] = 1;
        bfs.push({ 0, 0, 0 });
    } else {
        cout << "No" << endl;
        return 0;
    }
    string snuke = "snuke";
    while (!bfs.empty()) {
        auto [x, y, l] = bfs.front();
        bfs.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (valid(nx, ny, N, M) 
                && snuke[(l + 1) % 5] == A[nx][ny]
                && !dp[nx][ny][(l+1)%5]) {
                    dp[nx][ny][(l+1)%5] = 1;
                    bfs.push({ nx, ny, (l+1)%5 });
                }
        }
    }
    for (int i = 0; i < 5; i++) {
        if (dp[N-1][M-1][i]) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}