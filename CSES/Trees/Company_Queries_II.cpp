#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<vector<int>> adj;
vector<vector<int>> jmp;
vector<int> time_in, time_out;
int timer = 0;
const int LOG = 20;

void dfs(int u, int p = 0) {
    time_in[u] = timer++;
    jmp[u][0] = p;
    for (int i = 1; i < LOG; i++) {
        jmp[u][i] = jmp[jmp[u][i-1]][i-1];
    }

    for (auto v: adj[u]) {
        if (v == p) continue;
        dfs(v, u);
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
    for (int i = 1; i < N; i++) {
        int parent;
        cin >> parent;
        parent--;
        adj[parent].push_back(i);
    }
    dfs(0);
    for (int i = 0; i < Q; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        cout << lca(u, v) + 1 << endl;
    }
    return 0;
}