#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<vector<int>> adj;
vector<int> dist;

int dfs(int u, int p = -1) {
    int sz = adj[u].size();
    for (int i = 0; i < sz; i++) {
        int v = adj[u][i];
        if (v == p) continue;
        auto d = dfs(v, u) + 1;
        dist[u] = max(dist[u], d);
    }
    return dist[u];
}

void dfs2(int u, int p = -1, int push = 0) {
    dist[u] = max(dist[u], push);
    int sz = adj[u].size();
    vector<int> pref(sz), suff(sz);
    for (int i = 0; i < sz; i++) {
        int v = adj[u][i];
        if (v == p) continue;
        pref[i] = dist[v];
        suff[i] = dist[v];
    }
    for (int i = 1; i < sz; i++) {
        pref[i] = max(pref[i], pref[i-1]);
    }
    for (int i = sz - 2; i >= 0; i--) {
        suff[i] = max(suff[i], suff[i+1]);
    }
    for (int i = 0; i < sz; i++) {
        int v = adj[u][i];
        if (v == p) continue;
        int p = (i ? pref[i-1] : -INT_MAX / 2);
        int s = (i == sz - 1 ? -INT_MAX / 2 : suff[i+1]);
        dfs2(v, u, max({ push + 1, p + 2, s + 2 }));
    }
}

int main() {
    int N;
    cin >> N;
    adj.resize(N);
    dist.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0);
    dfs2(0);
    for (int i = 0; i < N; i++) {
        cout << dist[i] << " ";
    } cout << endl;
    return 0;
}