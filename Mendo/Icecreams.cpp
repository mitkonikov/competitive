#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<vector<int>> up;
vector<int> depth;
vector<int> mapped;
const int LOG = 20;

void add(int u, int p) {
    depth[u] = depth[p] + 1;
    up[u][0] = p;
    for (int l = 1; l < LOG; l++) {
        up[u][l] = up[up[u][l-1]][l-1];
    }
}

int lca(int u, int v) {
    if (u == v) return u;
    if (depth[u] > depth[v]) swap(u, v);
    for (int i = depth[v] - depth[u], k = 0; i > 0; i /= 2, k++) {
        if (i & 1) v = up[v][k];
    }
    if (u == v) return u;
    for (int i = LOG - 1; i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

int main() {
    int N;
    cin >> N;
    depth.resize(N + 10);
    up.resize(N + 10, vector<int>(LOG, 0));
    mapped.resize(N + 10);
    for (int i = 1; i <= N; i++) {
        char c;
        cin >> c;
        if (c == 'a') {
            int u;
            cin >> u;
            add(i, mapped[u]);
            mapped[i] = i;
        } else if (c == 'b') {
            int u;
            cin >> u;
            u = mapped[u];
            int p = up[u][0];
            cout << u << endl;
            mapped[i] = p;
        } else {
            int u, v;
            cin >> u >> v;
            u = mapped[u];
            v = mapped[v];
            mapped[i] = u;
            cout << depth[lca(u, v)] << endl;
        }
    }
    return 0;
}
