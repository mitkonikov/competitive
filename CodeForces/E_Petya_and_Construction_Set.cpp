#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<vector<int>> adj, at_depth;
vector<int> mapped, depth;

void dfs(int u, int p) {
    if (p != -1) {
        int U = mapped[u];
        int P = mapped[p];
        cout << P << " " << U << endl;
    }
    for (auto v: adj[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
}

int main() {
    int N;
    cin >> N;
    vector<int> D(N);
    for (int i = 0; i < N; i++) cin >> D[i];
    vector<int> order(N);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int a, int b) {
        return D[a] > D[b];
    });
    int node = 0;
    adj.resize(2 * N + 1);
    mapped.resize(2 * N + 1, -1);
    depth.resize(2 * N + 1);
    at_depth.resize(2 * N + 1);
    depth[0] = 0;
    at_depth[0].push_back(0);
    vector<set<int>> free(2 * N + 1);
    int last = 0;
    int node_counter = 0;
    auto add_node = [&](int u) {
        int v = node_counter + 1;
        adj[u].push_back(v);
        adj[v].push_back(u);
        depth[v] = depth[u] + 1;
        at_depth[depth[v]].push_back(v);
        free[depth[v]].insert(v);
        if (depth[v] > depth[last]) last = v;
        node_counter++;
    };
    for (int i = 0; i < N; i++) {
        int u1 = 2 * order[i] + 1;
        int u2 = 2 * order[i] + 2;
        while (mapped[node] != -1) {
            node++;
            assert(node < 2 * N);
        }
        if (node != 0 && node >= node_counter) {
            // it's an edge case
            if (D[order[i]] > 1) {
                add_node(0);
                mapped[node_counter] = u1;
                add_node(at_depth[D[order[i]] - 2][0]);
                mapped[node_counter] = u2;
            } else {
                add_node(0);
                mapped[node_counter] = u1;
                add_node(node_counter);
                mapped[node_counter] = u2;
            }
            continue;
        }
        mapped[node] = u1;
        int d = D[order[i]] + depth[node];
        // branch if needed
        if (free[d].empty() && !at_depth[d].empty()) {
            int some_parent = at_depth[d-1][0];
            add_node(some_parent);
        }
        while (free[d].empty()) {
            add_node(last);
        }
        auto it = free[d].begin();
        free[d].erase(it);
        mapped[*it] = u2;
    }
    dfs(0, -1);
    return 0;
}