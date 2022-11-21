#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

vector<vector<int>> adj;
vector<int> v;

struct D {
    int node;
    int flow;

    bool operator>(const D &d) const {
        return (flow > d.flow);
    }
    bool operator<(const D &d) const {
        return (flow < d.flow);
    }
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    adj.resize(n);
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<D> pq;
    pq.push({ 0, v[0] });
    vector<bool> visited(n, false);
    vector<int> FLOW(n, 0);
    vector<int> dist(n, INT_MAX);
    FLOW[0] = v[0];
    dist[0] = 1;
    while (!pq.empty()) {
        auto top = pq.front();
        pq.pop();

        int flow = min(top.flow, v[top.node]);
        visited[top.node] = true;
        if (dist[top.node] + 1 > k) continue;
        for (auto u: adj[top.node]) {
            if (FLOW[u] == min(v[u], FLOW[top.node])) {
                if (dist[u] > dist[top.node] + 1) {
                    dist[u] = dist[top.node] + 1;
                    pq.push({ u, FLOW[u] });
                }
            } else if (FLOW[u] < min(v[u], FLOW[top.node])) {
                FLOW[u] = min(v[u], FLOW[top.node]);
                dist[u] = dist[top.node] + 1;
                pq.push({ u, FLOW[u] });
            }
        }
    }

    cout << min(v[n-1], FLOW[n-1]) << " " << dist[n-1] << endl;
    return 0;
}