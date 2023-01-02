#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M, K;
    cin >> N >> M >> K;
    vector<int> toggle(K);
    for (int i = 0; i < K; i++) {
        cin >> toggle[i];
    }
    vector<vector<pair<int, int>>> adj(N);
    for (int i = 0; i < M; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        u--; v--;
        adj[u].push_back({ v, c });
        adj[v].push_back({ u, c });
    }
    const int INF = 1e9;
    vector<vector<int>> dist(N, vector<int>((1<<K) + 10, INF));
    dist[0][0] = 0;
    struct d {
        int node, cost, mask;
        bool operator>(const d& other) const {
            return (cost > other.cost);
        }
    };
    priority_queue<d, vector<d>, greater<d>> pq;
    pq.push({ 0, 0, 0 });
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        if (top.cost > dist[top.node][top.mask]) continue;

        for (auto edge: adj[top.node]) {
            if (dist[edge.first][top.mask] > top.cost + edge.second) {
                dist[edge.first][top.mask] = top.cost + edge.second;
                pq.push({ edge.first, top.cost + edge.second, top.mask });
            }

            for (int t = 0; t < (1 << K); t++) {
                if (t & top.mask) continue;
                int new_cost = edge.second;
                for (int j = 0; j < K; j++) if (t & (1 << j)) new_cost &= ~(1 << toggle[j]);
                if (dist[edge.first][top.mask | t] > (dist[top.node][top.mask] + new_cost)) {
                    dist[edge.first][top.mask | t] = (dist[top.node][top.mask] + new_cost);
                    pq.push({ edge.first, dist[edge.first][top.mask | t], top.mask | t });
                }
            }
        }
    }
    int ans = INF;
    for (int i = 0; i < (1 << K); i++) {
        ans = min(ans, dist[N-1][i]);
    }
    cout << ans << endl;
    return 0;
}