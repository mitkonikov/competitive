#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<bool> sw;
vector<vector<vector<int>>> adj;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    adj.resize(n, vector<vector<int>>(2));
    sw.resize(n, false);
    for (int i = 0; i < m; i++) {
        int u, v, a;
        cin >> u >> v >> a;
        u--; v--;
        adj[u][a].push_back(v);
        adj[v][a].push_back(u);
    }
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        sw[x-1] = true;
    }
    vector<vector<int>> dist(2, vector<int>(n, INT_MAX / 10));
    queue<pair<int, bool>> bfs; // { node, flip };
    bfs.push({ 0, 1 });
    dist[1][0] = 0;
    while (!bfs.empty()) {
        auto top = bfs.front();
        bfs.pop();

        if (sw[top.first]) {
            for (auto el: adj[top.first][top.second ^ 1]) {
                if (dist[top.second ^ 1][el] > dist[top.second][top.first] + 1) {
                    dist[top.second ^ 1][el] = dist[top.second][top.first] + 1;
                    bfs.push({ el, top.second ^ 1 });
                }
            }
        }

        for (auto el: adj[top.first][top.second]) {
            if (dist[top.second][el] > dist[top.second][top.first] + 1) {
                dist[top.second][el] = dist[top.second][top.first] + 1;
                bfs.push({ el, top.second });
            }
        }
    }
    int ans = min(dist[0][n-1], dist[1][n-1]);
    if (ans != INT_MAX / 10) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}