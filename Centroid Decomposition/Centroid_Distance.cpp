#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int inf = (int)1e9;

struct CentroidDecomposition {
    vector<vector<int>> G;
    vector<map<int, int>> dis;
    vector<int> sz, pa, ans;
    vector<bool> checked;

    CentroidDecomposition(int N) {
        G.resize(N);
        dis.resize(N);
        sz.resize(N);
        pa.resize(N);
        ans.resize(N);
        checked.resize(N);
        for (int i = 0; i < N; ++i) {
            G[i].clear();
            dis[i].clear();
            ans[i] = inf;
        }
    }
    void addEdge(int u, int v) {
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int dfs(int u, int p) {
        sz[u] = 1;
        for (auto v : G[u]) {
            if (v == p || checked[v]) continue;
            sz[u] += dfs(v, u);
        }
        return sz[u];
    }
    int centroid(int u, int p, int n) {
        for (auto v : G[u]) {
            if (v == p || checked[v]) continue;
            if (sz[v] > n / 2) return centroid(v, u, n);
        }
        return u;
    }
    void dfs2(int u, int p, int c, int d) {
        dis[c][u] = d; // distance from centroid to me
        for (auto v : G[u]) {
            if (v == p || checked[v]) continue;
            dfs2(v, u, c, d + 1);
        }
    }
    void build(int u, int p) {
        int n = dfs(u, p);
        int c = centroid(u, p, n);
        if (p == -1) p = c;
        pa[c] = p;
        dfs2(c, p, c, 0);
        checked[c] = true;

        for (auto v : G[c]) {
            if (v == p || checked[v]) continue;
            build(v, c);
        }
    }
    void modify(int u) {
        for (int v = u; v != 0; v = pa[v]) {
            ans[v] = min(ans[v], dis[v][u]);
        }
    }
    int query(int u) {
        int mn = inf;
        for (int v = u; v != 0; v = pa[v]) {
            mn = min(mn, ans[v] + dis[v][u]);
        }
        return mn;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int N, Q;
    cin >> N >> Q;
    CentroidDecomposition cd(N + 10);
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        cd.addEdge(a, b);
    }
    cd.build(1, 0); // Don't forget it!
    cd.modify(1);
    while (Q--) {
        int t, u;
        cin >> t >> u;
        if (t == 1)
            cd.modify(u);
        else
            cout << cd.query(u) << '\n';
    }
}