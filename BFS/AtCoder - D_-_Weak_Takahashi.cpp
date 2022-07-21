#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> board(n);
    for (int i = 0; i < n; i++) cin >> board[i];

    queue<pair<int, int>> q;
    q.push({ 0, 0 });
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    dist[0][0] = 1;
    const int dx[4] = { 0, 1 };
    const int dy[4] = { 1, 0 };
    int ans = 1;
    while (!q.empty()) {
        auto top = q.front();
        q.pop();

        for (int dir = 0; dir < 2; dir++) {
            int nx = top.first + dx[dir];
            int ny = top.second + dy[dir];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && board[nx][ny] == '.') {
                if (dist[nx][ny] > dist[top.first][top.second] + 1) {
                    dist[nx][ny] = dist[top.first][top.second] + 1;
                    q.push({ nx, ny });
                    ans = max(ans, dist[nx][ny]);
                }
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}