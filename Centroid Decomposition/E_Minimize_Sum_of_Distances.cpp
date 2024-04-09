#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

vector<vector<int>> adj;

struct CentroidDecomposition {
    vector<vector<int>> G;
    vector<ll> C;
    vector<int> sz, pa;
    vector<ll> ans;
    vector<bool> checked;

    CentroidDecomposition(int N) {
        G.resize(N);
        sz.resize(N);
        pa.resize(N);
        ans.resize(N);
        checked.resize(N);
        C.resize(N);
        for (int i = 0; i < N; ++i) {
            G[i].clear();
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
    pair<ll, ll> dfs2(int u, int p, int c, int d) {
        // dis[c][u] = d;
        pair<ll, ll> result = { 0, C[u] };
        for (auto v : G[u]) {
            if (v == p || checked[v]) continue;
            auto ch = dfs2(v, u, c, d + 1);
            result.first += ch.first + ch.second;
            result.second += ch.second;
        }
        return result;
    }
    void dfs3(int u, int p, int c, pair<ll, ll> push) {
        push.first += push.second;
        ans[u] += push.first;
        for (auto v : G[u]) {
            if (v == p || checked[v]) continue;
            dfs3(v, u, c, push);
        }
    }
    void build(int u, int p) {
        int n = dfs(u, p);
        int c = centroid(u, p, n);
        if (p == -1) p = c;
        pa[c] = p;

        vector<pair<ll, ll>> results(G[c].size());
        pair<ll, ll> sum = { 0, 0 };
        for (int i = 0; i < G[c].size(); i++) {
            auto v = G[c][i];
            if (v == p || checked[v]) continue;
            results[i] = dfs2(v, c, c, 1);
            results[i].first += results[i].second;
            sum.first += results[i].first;
            sum.second += results[i].second;
        }

        ans[c] += sum.first;

        for (int i = 0; i < G[c].size(); i++) {
            auto v = G[c][i];
            if (v == p || checked[v]) continue;
            pair<ll, ll> push = sum;
            push.first -= results[i].first;
            push.second -= results[i].second;
            push.second += C[c];
            dfs3(v, c, c, push);
        }

        checked[c] = true;
        for (auto v : G[c]) {
            if (v == p || checked[v]) continue;
            build(v, c);
        }
    }
};

int main() {
    int N;
    cin >> N;
    CentroidDecomposition cd(N + 3);
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        cd.addEdge(a, b);
    }
    for (int i = 0; i < N; i++) {
        cin >> cd.C[i + 1];
    }
    cd.build(1, 0);
    ll ans = LLONG_MAX;
    for (int i = 1; i <= N; i++) ans = min(ans, cd.ans[i]);
    cout << ans << endl;
    return 0;
}