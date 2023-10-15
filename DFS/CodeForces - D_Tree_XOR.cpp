#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int N;
vector<vector<int>> adj;
vector<ll> subsize;
vector<ll> cost_root;
vector<ll> A;
vector<ll> ans;

int dfs(int u, int p) {
    subsize[u] = 1;
    for (auto v: adj[u]) {
        if (v == p) continue;
        subsize[u] += dfs(v, u);
    }
    return subsize[u];
}

ll dfs1(int u, int p) {
    cost_root[u] = 0;
    for (auto v: adj[u]) {
        if (v == p) continue;
        cost_root[u] += dfs1(v, u);
        cost_root[u] += (ll)(A[u] ^ A[v]) * subsize[v];
    }
    return cost_root[u];
}

void dfs2(int u, int p, ll cost) {
    int t = adj[u].size();
    ans[u] = cost_root[u] + cost + (ll)(A[u] ^ A[p]) * (N - subsize[u]);
    for (int i = 0; i < t; i++) {
        auto v = adj[u][i];
        if (v == p) continue;
        dfs2(v, u, ans[u] - (ll)(A[u] ^ A[v]) * subsize[v] - cost_root[v]);
    }
}

void testCase() {
    cin >> N;
    A.clear();
    A.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    adj.clear();
    adj.resize(N);
    vector<pair<int, int>> edges(N - 1);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges[i] = { u, v };
    }
    subsize.clear();
    subsize.resize(N);
    ans.clear();
    ans.resize(N);
    cost_root.clear();
    cost_root.resize(N);
    dfs(0, -1);
    dfs1(0, -1);
    dfs2(0, -1, 0);
    for (auto el: ans) cout << el << " ";
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    cout << flush;
    return 0;
}