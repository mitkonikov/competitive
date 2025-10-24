#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<pair<int, int>>> adj(N);
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back({ v, w });
    }
    vector<vector<bool>> visited((1 << 10) + 10, vector<bool>(N, false));
    queue<pair<int, int>> bfs;
    bfs.push({ 0, 0 });
    visited[0][0] = true;
    while (!bfs.empty()) {
        auto [u, x] = bfs.front();
        bfs.pop();
        for (auto [v, w] : adj[u]) {
            if (!visited[x ^ w][v]) {
                visited[x ^ w][v] = true;
                bfs.push({ v, x^w });
            }
        }
    }
    for (int x = 0; x < visited.size(); x++) {
        if (visited[x][N-1]) {
            cout << x << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}