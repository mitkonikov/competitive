#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

inline bool valid(int x, int y, int n) {
    return (x >= 0 && x < n && y >= 0 && y < n);
}

int main() {
    int n;
    cin >> n;

    int a, b;
    cin >> a >> b;
    a--; b--;

    int c, d;
    cin >> c >> d;
    c--; d--;

    vector<string> board(n);
    for (int i = 0; i < n; i++) cin >> board[i];
    
    if ((a + b) % 2 != (c + d) % 2) {
        cout << -1 << endl;
        return 0;
    }

    struct state {
        int moves = 0;
        int x, y;
        int prev_dir = 0;

        bool operator>(const state &other) {
            return (moves > other.moves);
        }
    };

    struct Compare {
        bool operator()(state const& p1, state const& p2) {
            return p1.moves > p2.moves;
        }
    };

    priority_queue<state, vector<state>, Compare> pq;

    int dx[4] = { -1, -1, 1, 1 };
    int dy[4] = { -1, 1, -1, 1 };
    int op[4] = {  3, 2, 1, 0 };

    int dp[n][n][4];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int dir = 0; dir < 4; dir++) {
                dp[i][j][dir] = INT_MAX;
            }
        }
    }

    for (int dir = 0; dir < 4; dir++) {
        int nx = a + dx[dir];
        int ny = b + dy[dir];
        if (valid(nx, ny, n) && board[nx][ny] == '.') {
            pq.push({ 1, nx, ny, dir });
            dp[nx][ny][dir] = 1;
        }
    }

    while (!pq.empty()) {
        auto top = pq.top(); pq.pop();
        if (dp[top.x][top.y][top.prev_dir] < top.moves) continue;
        for (int dir = 0; dir < 4; dir++) {
            if (dir == op[top.prev_dir]) continue;
            int nx = top.x + dx[dir];
            int ny = top.y + dy[dir];
            if (valid(nx, ny, n) && board[nx][ny] == '.') {
                int new_moves = top.moves + (dir != top.prev_dir);
                if (dp[nx][ny][dir] > new_moves) {
                    pq.push({ new_moves, nx, ny, dir });
                    dp[nx][ny][dir] = new_moves;
                }
            }
        }
    }

    int min_moves = INT_MAX;
    for (int dir = 0; dir < 4; dir++) {
        min_moves = min(min_moves, dp[c][d][dir]);
    }

    cout << (min_moves == INT_MAX ? -1 : min_moves) << endl;
    return 0;
}