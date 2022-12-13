// Task: https://mendo.mk/Task.do?id=302

#include <bits/stdc++.h>
#define ll long long

using namespace std;

int dist[110][10][460];
const int INF = 1e9;

struct D {
    int node, dist, k, l;

    bool operator>(const D& other) const {
        if (dist != other.dist) return (dist > other.dist);
        if (k != other.k) return (k < other.k);
        return (l < other.l);
    }
};

int main() {
    for (int i = 0; i < 110; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 460; k++) {
                dist[i][j][k] = INF;
            }
        }
    }

    int N, X;
    cin >> N >> X;
    int K, L;
    cin >> K >> L;
    int M;
    cin >> M;
    vector<vector<pair<int, int>>> adj(N);
    for (int i = 0; i < M; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        u--; v--;
        adj[u].push_back({ v, c });
        adj[v].push_back({ u, c });
    }
    priority_queue<D, vector<D>, greater<D>> pq;
    pq.push({ 0, 0, K, 0 });
    dist[0][K][0] = 0;
    int ans = INT_MAX;
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        if (top.node == N-1) ans = min(ans, top.dist);
        if (top.node < X) top.l = 0;
        for (auto edge: adj[top.node]) {
            int v = edge.first;
            int c = edge.second;
            if (top.l > 0) {
                if (c <= top.l && dist[v][top.k][top.l-c] > top.dist) {
                    dist[v][top.k][top.l-c] = top.dist;
                    pq.push({ v, top.dist, top.k, top.l-c });
                }
            }
            // try using a power
            if (top.k > 0 && L-c >= 0 && dist[v][top.k-1][L-c] > top.dist) {
                dist[v][top.k-1][L-c] = top.dist;
                pq.push({ v, top.dist, top.k-1, L-c });
            }
            // try going there without using the power
            if (dist[v][top.k][0] > top.dist + c) {
                dist[v][top.k][0] = top.dist + c;
                pq.push({ v, top.dist + c, top.k, 0 });
            }
        }
    }
    cout << ans << endl;
    return 0;
}