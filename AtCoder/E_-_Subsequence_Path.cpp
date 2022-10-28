#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct edge {
    int u, v, w;

    void read() {
        cin >> u >> v >> w;
        u--; v--;
    }
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<edge> edges(m);
    for (int i = 0; i < m; i++) {
        edges[i].read();
    }

    vector<ll> cost(n, LLONG_MAX / 10);
    cost[0] = 0;
    for (int i = 0; i < k; i++) {
        int e;
        cin >> e;
        e--;

        cost[edges[e].v] = min(cost[edges[e].v], cost[edges[e].u] + edges[e].w);
    }

    if (cost[n-1] == LLONG_MAX / 10) {
        cout << -1 << endl;
    } else {
        cout << cost[n-1] << endl;
    }

    return 0;
}