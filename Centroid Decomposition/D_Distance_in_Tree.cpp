#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

struct CentroidDecomposition {
    vector<vector<int>> G;
    vector<int> sz, pa;
    vector<bool> checked;
    vector<ll> len, new_len;
    ll ans = 0;
    int k;

    CentroidDecomposition(int N, int K) {
        G.resize(N);
        sz.resize(N);
        pa.resize(N);
        checked.resize(N);
        len.resize(K + 10);
        new_len.resize(K + 10);
        k = K;
    }
    void addEdge(int u, int v) {
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int dfs(int u, int p) {
        sz[u] = 1;
        for (auto v: G[u]) {
            if (v == p || checked[v]) continue;
            sz[u] += dfs(v, u);
        }
        return sz[u];
    }
    int centroid(int u, int p, int n) {
        for (auto v: G[u]) {
            if (v == p || checked[v]) continue;
            if (sz[v] > n / 2) return centroid(v, u, n);
        }
        return u;
    }
    void dfs2(int u, int p, int c, int d, bool s = true) {
        if (!s && k - d > 0) ans += len[k - d];
        if (!s && d <= k) new_len[d]++;
        for (auto v: G[u]) {
            if (v == p || checked[v]) continue;
            dfs2(v, u, c, d + 1, false);
            if (s) for (int i = 0; i <= k; i++) {
                len[i] += new_len[i];
                new_len[i] = 0;
            }
        }
        if (s) ans += len[k];
    }
    void build(int u, int p) {
        int n = dfs(u, p);
        int c = centroid(u, p, n);
        if (p == -1) p = c;
        pa[c] = p;
        fill(len.begin(), len.end(), 0);
        dfs2(c, p, c, 0);
        checked[c] = true;

        for (auto v: G[c]) {
            if (v == p || checked[v]) continue;
            build(v, c);
        }
    }
};

int main() {
    int N, K;
    cin >> N >> K;
    CentroidDecomposition CD(N + 10, K);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        CD.addEdge(u, v);
    }
    CD.build(1, 0);
    cout << CD.ans << endl;
}