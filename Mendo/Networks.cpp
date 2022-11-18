// Task: https://mendo.mk/Task.do?id=56

#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct Graph {
    struct edge {
        int u, v, cost;

        bool operator<(const edge& other) const {
            return (cost < other.cost);
        }
    };

    vector<vector<pair<int, int>>> adj;
    int N;

    Graph(int n) {
        adj.resize(n);
        N = n;
    }

    void add_edge(edge e) {
        add_edge(e.u, e.v, e.cost);
    }

    void add_edge(int u, int v, int cost) {
        adj[u].push_back({ v, cost });
        adj[v].push_back({ u, cost });
    }

    int distance(int u, int v) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(N, INT_MAX);
        pq.push({ 0, u });
        dist[u] = 0;
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            for (auto edge: adj[top.second]) {
                int v = edge.first;
                if (dist[v] > dist[top.second] + edge.second) {
                    dist[v] = dist[top.second] + edge.second;
                    pq.push({ dist[v], v });
                }
            }
        }
        return dist[v];
    }
};

int main() {
    int l;
    cin >> l;
    vector<int> ans;
    for (int tt = 0; tt < l; tt++) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> shortest(n, vector<int>(n, 0));
        vector<Graph::edge> edges;
        for (int i = 1; i <= n - 1; i++) {
            for (int j = 1; j <= (n - i); j++) {
                int u = i - 1;
                int v = (i + j) - 1;
                int cost;
                cin >> cost;
                shortest[u][v] = cost;
                shortest[v][u] = cost;
                edges.push_back({ u, v, cost });
            }
        }
        sort(edges.begin(), edges.end());
        Graph G(n);
        int count = 0;
        for (int i = 0; i < edges.size(); i++) {
            int shortest = G.distance(edges[i].v, edges[i].u);
            if (shortest > edges[i].cost) {
                G.add_edge(edges[i]);
                count++;
            } else if (shortest < edges[i].cost) {
                ans.push_back(tt);
                count = 0;
                break;
            }
        }
        if (count > k) {
            ans.push_back(tt);
        }
    }
    cout << ans.size() << endl;
    for (auto el: ans) {
        cout << el + 1 << endl;
    }
    return 0;
}