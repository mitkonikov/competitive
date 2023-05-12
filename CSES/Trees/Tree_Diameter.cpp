#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<vector<int>> adj;

pair<int, int> bfs(int u, int N) {
    vector<int> dist(N, INT_MAX);
    queue<int> q;
    q.push(u);
    int last = u;
    dist[u] = 0;
    while (!q.empty()) {
        auto t = q.front();
        last = t;
        q.pop();
        for (auto v: adj[t]) {
            if (dist[v] > dist[t] + 1) {
                dist[v] = dist[t] + 1;
                q.push(v);
            }
        }
    }
    return { last, dist[last] };
}

int main() {
    int N;
    cin >> N;
    adj.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    auto [e1, d1] = bfs(0, N);
    auto [e2, d2] = bfs(e1, N);
    cout << d2 << endl;
    return 0;
}