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
        depth.resize(n);
        preprocess(root);
    }

    ~LCA() {
        tin.clear();
        tout.clear();
        up.clear();
        adj.clear();
    }

    void dfs(int v, int p, int d = 0) {
        depth[v] = d;
        tin[v] = ++timer;
        up[v][0] = p;
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

    void preprocess(int root) {
        tin.resize(n);
        tout.resize(n);
        timer = 0;
        l = ceil(log2(n));
        up.assign(n, vector<int>(l + 1));
        dfs(root, root);
    }
};

inline char gc() { // like getchar()
	static char buf[1 << 16];
	static size_t bc, be;
	if (bc >= be) {
		buf[0] = 0, bc = 0;
		be = fread(buf, 1, sizeof(buf), stdin);
	}
	return buf[bc++]; // returns 0 on EOF
}

int readInt() {
	int a, c;
	while ((a = gc()) < 40);
	if (a == '-') return -readInt();
	while ((c = gc()) >= 48) a = a * 10 + c - 480;
	return a - 48;
}

void testCase() {
    int N = readInt(), Q = readInt();
    vector<vector<int>> adj(N);
    for (int i = 0; i < N - 1; ++i) {
        int a = readInt(), b = readInt();
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    LCA lca(adj, 0);
    while (Q--) {
        int K = readInt();
        vector<int> A(K);
        for (int i = 0; i < K; i++) {
            A[i] = readInt() - 1;
        }
        if (K == 1) {
            cout << 0 << endl;
            continue;
        }
        auto dist = [&](int u, int v, int l) {
            return lca.depth[u] + lca.depth[v] - 2 * lca.depth[l];
        };
        sort(A.begin(), A.end(), [&](int a, int b) {
            return lca.depth[a] > lca.depth[b];
        });
        int ans = 0;
        for (int i = 0; i < K; i++) {
            ans = max(ans, dist(A[0], A[i], lca.lca(A[0], A[i])));
        }
        cout << (ans + 1) / 2 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    t = readInt();

    while (t--) {
        testCase();
    }

    cout << flush;
    return 0;
}