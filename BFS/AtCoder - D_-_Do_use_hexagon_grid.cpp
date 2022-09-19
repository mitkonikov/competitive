#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int dx[6] = { -1, -1, 0, 0, 1, 1 };
int dy[6] = { -1, 0, -1, 1, 0, 1 };

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> sq(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        sq[i] = { x, y };
    }
    vector<bool> visited(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        ans++;
        queue<int> bfs;
        bfs.push(i);
        while (!bfs.empty()) {
            auto top = bfs.front();
            bfs.pop();
            visited[top] = true;
            for (int dir = 0; dir < 6; dir++) {
                int nx = sq[top].first + dx[dir];
                int ny = sq[top].second + dy[dir];
                for (int j = 0; j < n; j++) {
                    if (sq[j] == make_pair(nx, ny)) {
                        if (!visited[j]) {
                            bfs.push(j);
                            visited[j] = true;
                        }
                        break;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    cout << flush;
    return 0;
}