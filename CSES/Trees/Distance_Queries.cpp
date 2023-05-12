#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<vector<int>> adj;
vector<vector<int>> jmp;
vector<int> time_in, time_out, depth;
int timer = 0;
const int LOG = 20;

void dfs(int u, int p = 0, int d = 0) {
    time_in[u] = timer++;
    depth[u] = d;
    jmp[u][0] = p;
    for (int i = 1; i < LOG; i++) {
        jmp[u][i] = jmp[jmp[u][i-1]][i-1];
    }

    for (auto v: adj[u]) {
        if (v == p) continue;
        dfs(v, u, d + 1);
    }

    time_out[u] = timer;
}

// u is ancestor of v
bool is_ancestor(int u, int v) {
    return (time_in[u] <= time_in[v] && time_out[v] <= time_out[u]);
}

int lca(int u, int v) {
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;
    for (int i = LOG - 1; i >= 0; i--) {
        if (!is_ancestor(jmp[u][i], v)) {
            u = jmp[u][i];
        }
    }
    return jmp[u][0];
}

int main() {
    int N, Q;
    cin >> N >> Q;
    adj.resize(N);
    jmp.resize(N, vector<int>(LOG, 0));
    time_in.resize(N);
    time_out.resize(N);
    depth.resize(N);
    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0);
    for (int i = 0; i < Q; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        int l = lca(u, v);
        int dist = depth[u] + depth[v] - 2 * depth[l];
        cout << dist << endl;
    }
    return 0;
}