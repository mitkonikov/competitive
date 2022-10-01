#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct edge {
    int start;
    int end;
    int w;
    bool taken = false;
    int id;
};

int n, m;
vector<edge> edges;
vector<vector<edge>> adj;

int main() {
    cin >> n >> m;

    edges.resize(m);
    adj.resize(n);

    for (int i = 0; i < m; i++) {
        int start, end, w;
        cin >> start >> end >> w;
        start--; end--;
        edges[i] = {start, end, w, false, i};
        adj[start].push_back(edges[i]);
        adj[end].push_back(edges[i]);
    }

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({ 0, 0 });
    vector<ll> dist(n, LLONG_MAX);
    vector<int> parent(n, -1);
    dist[0] = 0;
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        int u = top.second;
        for (auto e: adj[u]) {
            int v = (e.start == u ? e.end : e.start);
            if (dist[v] > dist[u] + e.w) {
                dist[v] = dist[u] + e.w;
                pq.push({ dist[v], v });
                parent[v] = u;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        if (parent[edges[i].start] == edges[i].end || parent[edges[i].end] == edges[i].start) {
            cout << edges[i].id + 1 << " ";
        }
    }
    
    cout << endl;
    return 0;
}