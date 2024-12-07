#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

struct LCA {
    int n, l;
    vector<vector<int>> adj;

    int timer;
    vector<int> tin, tout;
    vector<vector<int>> up;
    vector<int> depth;

    LCA(vector<vector<int>> adj, int root) {
        this->n = adj.size();
        this->adj = adj;
        preprocess(root);
    }

    ~LCA() {
        tin.clear();
        tout.clear();
        up.clear();
        adj.clear();
    }

    void dfs(int v, int p, int d = 0) {
        tin[v] = ++timer;
        up[v][0] = p;
        depth[v] = d;
        for (int i = 1; i <= l; ++i)
            up[v][i] = up[up[v][i-1]][i-1];

        for (int u : adj[v]) {
            if (u != p)
                dfs(u, v, d + 1);
        }

        tout[v] = ++timer;
    }

    bool is_ancestor(int u, int v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }

    int lca(int u, int v) {
        if (is_ancestor(u, v))
            return u;
        if (is_ancestor(v, u))
            return v;
        for (int i = l; i >= 0; --i) {
            if (!is_ancestor(up[u][i], v))
                u = up[u][i];
        }
        return up[u][0];
    }

    int jump(int x, int k) {
        int u = x;
        if (k == 0) return x;
        for (int i = 0; i <= l; i++) {
            if (k & (1 << i)) u = up[u][i];
        }
        return u;
    }

    void preprocess(int root) {
        tin.resize(n);
        tout.resize(n);
        timer = 0;
        l = ceil(log2(n));
        up.assign(n, vector<int>(l + 1));
        depth.resize(n);
        dfs(root, root);
    }
};

vector<ll> V, F, subtree_sum;
vector<vector<int>> adj;

void dfs(int u, int p) {
    for (auto v: adj[u]) {
        if (v == p) continue;
        dfs(v, u);
    }

    for (auto v: adj[u]) {
        if (v == p) continue;
        subtree_sum[u] += subtree_sum[v];
        F[u] += F[v] + subtree_sum[v];
    }

    subtree_sum[u] += V[u];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, Q;
    cin >> N >> Q;
    V.resize(N, 0);
    F.resize(N, 0);
    adj.resize(N);
    subtree_sum.resize(N, 0);
    for (int i = 0; i < N; i++) cin >> V[i];
    vector<int> P(N, -1);
    for (int i = 1; i < N; i++) {
        cin >> P[i];
        P[i]--;
        adj[P[i]].push_back(i);
    }
    dfs(0, -1);
    LCA lca(adj, 0);
    for (int i = 0; i < Q; i++) {
        int X, Y;
        cin >> X >> Y;
        X--; Y--;
        if (P[X] == Y) {
            cout << F[Y] << endl;
            continue;
        }
        int diff = lca.depth[X] - lca.depth[Y];
        int S = lca.jump(X, diff - 1);
        auto ans = F[Y];
        ans += subtree_sum[S];
        ans += V[X];
        ans -= subtree_sum[X];
        ans -= V[X] * diff;
        cout << ans << endl;
    }
    return 0;
}