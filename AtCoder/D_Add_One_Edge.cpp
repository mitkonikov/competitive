#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

vector<vector<int>> adj;

int bfs(int u) {
    queue<int> q;
    q.push(u);
    vector<int> dist(adj.size(), INT_MAX);
    dist[u] = 0;
    int ans = 0;
    while (!q.empty()) {
        auto t = q.front();
        q.pop();

        for (int v: adj[t]) {
            if (dist[v] > dist[t] + 1) {
                dist[v] = dist[t] + 1;
                q.push(v);
                ans = max(ans, dist[v]);
            }
        }
    }
    return ans;
}

int main() {
    int N1, N2, M;
    cin >> N1 >> N2 >> M;
    adj.resize(N1 + N2);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << bfs(0) + bfs(N1 + N2 - 1) + 1 << endl;
    return 0;
}